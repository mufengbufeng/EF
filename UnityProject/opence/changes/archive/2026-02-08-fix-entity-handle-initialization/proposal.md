# Proposal: fix-entity-handle-initialization

## Why

The `EntityManager.ShowEntityAsync` method was setting the `Handle` property **after** calling `OnInit`, which caused a `NullReferenceException` when `OnShow` was invoked. The `EnemyEntity.OnShow` method attempts to access `Handle` to:
- Activate the GameObject (`Handle.SetActive(true)`)
- Get the Animator component (`Handle.GetComponent<Animator>()`)
- Set the spawn position (`Handle.transform.position = behaviorData.SpawnPosition`)

Since `Handle` was null during `OnShow`, these operations failed with a `NullReferenceException`.

## What Changes

This change reorders the initialization sequence in `EntityManager.ShowEntityAsync` to set the `Handle` property before calling `OnInit` and `OnShow` lifecycle callbacks.

**Modified Files**:
- `Assets/EF/EFRuntime/Entity/EntityManager.cs` - Reordered Handle initialization

**Specification Updates**:
- `entity-lifecycle-guarantee` - New spec defining Handle availability guarantees

## Root Cause

In `EntityManager.ShowEntityAsync` (line 310-328), the execution order was:
1. Instantiate GameObject
2. Call `OnInit`
3. Register entity
4. **Set Handle** ← Too late!
5. Call `OnShow` ← Handle is still null here

The `Handle` property needs to be available before any lifecycle callbacks (`OnInit`, `OnShow`) are invoked, as entities may need to access their GameObject during initialization.

## Proposed Solution

Reorder the initialization sequence in `EntityManager.ShowEntityAsync` to set the `Handle` property **before** calling `OnInit`:

1. Instantiate GameObject
2. **Set Handle** ← Move here
3. Call `OnInit`
4. Register entity
5. Call `OnShow` ← Handle is now available

This ensures that the `Handle` property is always available during entity lifecycle callbacks, which aligns with the expected behavior documented in the entity-module specification.

## Impact

- **Scope**: Single method change in `EntityManager.cs`
- **Risk**: Low - This is a simple reordering of operations with no logic changes
- **Breaking Changes**: None - This fixes a bug and makes behavior consistent with expectations
- **Testing**: Manual verification that enemy entities spawn without `NullReferenceException`

## Alternatives Considered

1. **Null-check in EnemyEntity.OnShow**: Would require all entity implementations to defensively check for null Handle, which is error-prone and doesn't address the root cause
2. **Lazy Handle initialization**: Would complicate the entity lifecycle and violate the principle that Handle should be available after OnInit

## Success Criteria

- Enemy entities spawn successfully without `NullReferenceException`
- `Handle` property is accessible in `OnInit` and `OnShow` callbacks
- All existing entity functionality continues to work
