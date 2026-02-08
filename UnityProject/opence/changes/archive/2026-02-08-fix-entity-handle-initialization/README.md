# Fix Entity Handle Initialization - Change Summary

## Overview

This change fixes a critical bug in the entity lifecycle where the `Handle` property was being set **after** `OnInit` was called, causing `NullReferenceException` when entities tried to access their GameObject during initialization callbacks.

## Problem

When spawning enemy entities, the following error occurred:
```
NullReferenceException: Object reference not set to an instance of an object
  at EnemyEntity.OnShow(Object userData)
```

The root cause was in `EntityManager.ShowEntityAsync` where the execution order was:
1. Instantiate GameObject
2. Call `OnInit` ← Entity callbacks start
3. Set `Handle` property ← Too late!
4. Call `OnShow` ← Handle is null, causing crash

## Solution

Reordered the initialization sequence to set `Handle` **before** calling any lifecycle callbacks:
1. Instantiate GameObject
2. Set `Handle` property ← Moved here
3. Call `OnInit` ← Handle is now available
4. Call `OnShow` ← Handle is still available

## Files Changed

### Implementation
- `Assets/EF/EFRuntime/Entity/EntityManager.cs` - Reordered Handle initialization

### Documentation
- `opence/changes/fix-entity-handle-initialization/proposal.md` - Problem analysis and solution proposal
- `opence/changes/fix-entity-handle-initialization/design.md` - Detailed design documentation
- `opence/changes/fix-entity-handle-initialization/tasks.md` - Implementation task list
- `opence/changes/fix-entity-handle-initialization/specs/entity-lifecycle-guarantee/spec.md` - Specification updates

## Testing

✅ **Manual Testing Completed**
- Enemy entities spawn without NullReferenceException
- Enemies appear at correct positions
- Enemy animations play correctly
- GameObject activation works as expected

## Impact

- **Scope**: Single method change in EntityManager
- **Risk**: Low - Simple reordering with no logic changes
- **Breaking Changes**: None - This is a bug fix
- **Performance**: No impact - same operations, just reordered

## Next Steps

1. ✅ Implementation complete
2. ✅ Testing complete
3. ✅ Documentation complete
4. ✅ Opence validation passed
5. 🔄 Ready for commit and archive

## Commit Message

```
fix(entity): Set Handle before OnInit to prevent NullReferenceException

The EntityManager was setting the Handle property after calling OnInit,
which caused NullReferenceException when entities tried to access their
GameObject during OnShow. This change reorders the initialization to
set Handle immediately after instantiation and before any lifecycle
callbacks are invoked.

Fixes: Enemy entities crashing on spawn
Change-Id: fix-entity-handle-initialization
```
