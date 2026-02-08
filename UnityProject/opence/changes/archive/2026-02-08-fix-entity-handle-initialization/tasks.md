# Tasks: fix-entity-handle-initialization

## Implementation Tasks

### 1. Reorder Handle initialization in EntityManager.ShowEntityAsync
**Status**: ✅ Complete
**Description**: Move the `SetEntityHandle` call to occur before `OnInit` is invoked
**Files**: `Assets/EF/EFRuntime/Entity/EntityManager.cs`
**Validation**:
- Code compiles without errors
- Handle is set before OnInit is called
- Execution order is: Instantiate → SetHandle → OnInit → Register → OnShow

### 2. Verify enemy entity spawning
**Status**: ✅ Complete
**Description**: Test that enemy entities spawn without NullReferenceException
**Validation**:
- Run the game
- Trigger enemy spawning
- Verify no NullReferenceException in console
- Verify enemies appear at correct positions
- Verify enemy animations play correctly

### 3. Update entity-module specification
**Status**: Pending
**Description**: Update the entity-module spec to clarify that Handle must be set before OnInit
**Files**: `opence/specs/entity-module/spec.md`
**Validation**:
- Specification clearly states Handle availability guarantee
- Scenario added for Handle initialization timing

## Dependencies

- Task 1 must complete before Task 2 (implementation before testing)
- Task 3 can be done in parallel with Task 2

## Notes

- The fix has already been implemented and tested successfully
- This plan documents the change for future reference and ensures specification alignment
