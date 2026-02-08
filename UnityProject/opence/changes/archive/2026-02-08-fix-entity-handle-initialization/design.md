# Design: fix-entity-handle-initialization

## Overview

This change fixes a critical bug in the entity lifecycle initialization sequence where the `Handle` property was being set after `OnInit` was called, causing `NullReferenceException` when entities tried to access their GameObject during `OnShow`.

## Architecture Context

### Entity Lifecycle Flow

The entity system follows this lifecycle:
1. **Creation**: Entity instance is obtained from object pool or created new
2. **Initialization**: `OnInit` is called with entity metadata
3. **Display**: `OnShow` is called to activate and configure the entity
4. **Update**: `OnUpdate` is called every frame while entity is active
5. **Hide**: `OnHide` is called to deactivate the entity
6. **Recycle**: `OnRecycle` is called when returning to object pool

### The Problem

The original implementation in `EntityManager.ShowEntityAsync` had this sequence:

```
1. Load asset
2. Instantiate GameObject
3. Call OnInit          ← Entity callbacks start
4. Register entity
5. Set Handle property  ← Too late!
6. Call OnShow          ← Handle is null here
```

This violated the implicit contract that `Handle` should be available during lifecycle callbacks.

## Design Decision

### Chosen Solution: Reorder Initialization

Move the `SetEntityHandle` call to occur immediately after instantiation and before any lifecycle callbacks:

```
1. Load asset
2. Instantiate GameObject
3. Set Handle property  ← Moved here
4. Call OnInit          ← Handle is now available
5. Register entity
6. Call OnShow          ← Handle is still available
```

### Rationale

1. **Minimal Change**: Only reorders existing operations, no new logic
2. **Consistent Behavior**: Handle is available throughout entire lifecycle
3. **No Breaking Changes**: Entities that didn't use Handle in OnInit/OnShow continue to work
4. **Fixes Root Cause**: Addresses the fundamental ordering issue rather than working around it

### Alternative Approaches Considered

#### 1. Lazy Handle Initialization
**Approach**: Initialize Handle on first access via property getter
**Rejected Because**:
- Adds complexity to property access
- Doesn't solve the timing issue
- Makes debugging harder

#### 2. Defensive Null Checks
**Approach**: Add null checks in all entity implementations
**Rejected Because**:
- Pushes responsibility to entity authors
- Error-prone (easy to forget checks)
- Doesn't fix the root cause
- Violates principle of least surprise

#### 3. Split OnInit into OnPreInit and OnPostInit
**Approach**: Add new lifecycle callback after Handle is set
**Rejected Because**:
- Breaking change requiring all entities to update
- Adds unnecessary complexity
- Doesn't provide clear value over simple reordering

## Implementation Details

### Code Change

**File**: `Assets/EF/EFRuntime/Entity/EntityManager.cs`
**Method**: `ShowEntityAsync`
**Lines**: 310-328

**Before**:
```csharp
GameObject instance = await _entityHelper.InstantiateEntityAsync(entityAsset, userData);

// 初始化实体
var isNewInstance = entity.EntityAssetName == null;
entity.OnInit(entityId, entityAssetName, entityGroup, isNewInstance, userData);

// 设置实体 Handle
if (entity is EntityBase entityBase)
{
    SetEntityHandle(entityBase, instance);
}
```

**After**:
```csharp
GameObject instance = await _entityHelper.InstantiateEntityAsync(entityAsset, userData);

// 设置实体 Handle（必须在 OnInit 之前设置）
if (entity is EntityBase entityBase)
{
    SetEntityHandle(entityBase, instance);
}

// 初始化实体
var isNewInstance = entity.EntityAssetName == null;
entity.OnInit(entityId, entityAssetName, entityGroup, isNewInstance, userData);
```

### Impact Analysis

**Affected Components**:
- `EntityManager.ShowEntityAsync`: Direct change
- All entity implementations: Benefit from guaranteed Handle availability
- `EnemyEntity`: Specifically fixes the NullReferenceException

**Performance Impact**: None - same operations, just reordered

**Memory Impact**: None - no new allocations

**Thread Safety**: No change - all operations remain on Unity main thread

## Testing Strategy

### Manual Testing
1. Run game and trigger enemy spawning
2. Verify no NullReferenceException in console
3. Verify enemies appear at correct positions
4. Verify enemy animations play correctly

### Regression Testing
1. Test other entity types (if any) to ensure they still work
2. Verify entity pooling still functions correctly
3. Verify entity hierarchy (parent/child) still works

### Edge Cases
- Entity with null Handle setter (shouldn't happen with EntityBase)
- Entity that overrides Handle property
- Entity instantiation failure (existing error handling should still work)

## Future Considerations

### Specification Update
The `entity-module` specification should be updated to explicitly state:
- Handle MUST be set before OnInit is called
- Entities MAY safely access Handle during OnInit and OnShow
- EntityManager implementations MUST guarantee Handle availability

### Documentation
Add inline comments in EntityManager to clarify the initialization order and why it matters.

## Rollback Plan

If issues arise, the change can be easily reverted by moving the `SetEntityHandle` call back to its original position. However, this would reintroduce the NullReferenceException bug.

## Success Metrics

- ✅ No NullReferenceException when spawning entities
- ✅ Enemy entities spawn and animate correctly
- ✅ No regression in existing entity functionality
- ✅ Code compiles without warnings
