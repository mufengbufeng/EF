# Skill Evaluation Checklist

Use this checklist before creating a new skill. All four questions must be answered satisfactorily.

## Four-Question Decision Framework

### Q1: What problem does this solve?

- [ ] Can you describe a specific, concrete problem or repeated workflow?
- [ ] Have you verified no existing skill solves this? (`opence skill list`)
- [ ] Would extending an existing skill be better than creating a new one?
- [ ] Is the problem general enough to apply beyond a single project?

**Stop if**: The problem is a one-off fix or only happened once. Write to `docs/solutions/` instead.

### Q2: Who uses it and when?

- [ ] Can you identify at least one clear user scenario?
- [ ] Can you list 3-5 trigger phrases a user would naturally say?
- [ ] Are these trigger phrases distinct from existing skills?

**Example trigger phrases:**
- "How do I deploy to staging?" → deploy-staging skill
- "Review this PR for security issues" → security-review skill
- "Set up a new microservice" → scaffold-service skill

**Stop if**: You can't think of 3 natural trigger phrases. The skill may be too niche.

### Q3: How should the description be written?

- [ ] Does the description start with an action verb?
- [ ] Does it include keywords users naturally say?
- [ ] Does it include at least one "Use when..." scenario?
- [ ] Is it specific enough that Claude knows when to use it, but broad enough to match future requests?

**Description template:**
```
"[Action verb] [what it does]. Use when [scenario 1], [scenario 2], or when the user asks '[natural phrase]'."
```

**Stop if**: The description is either too vague ("helps with code") or too specific ("fix bug #1234").

### Q4: Is it worth creating?

- [ ] Will this skill be used 3+ times in the next 6 months?
- [ ] Is the maintenance burden justified by the value?
- [ ] Does it encode knowledge that would otherwise be lost?

**Stop if**: Estimated usage < 3 times. Write to `docs/solutions/` instead.

## Skill vs. docs/solutions/ Decision Guide

| Signal | Create Skill | Write docs/solutions/ |
|--------|-------------|----------------------|
| Will recur frequently (3+ times/6 months) | ✅ | |
| One-time fix or rare edge case | | ✅ |
| Requires step-by-step workflow | ✅ | |
| Just a problem + root cause + fix | | ✅ |
| Other team members will need this | ✅ | |
| Only relevant to your context | | ✅ |
| Benefits from Claude auto-triggering | ✅ | |
| Reference-only (no automation needed) | | ✅ |

## Post-Creation Verification

After creating the skill:

1. Does `opence skill show <name>` display correctly?
2. Test the skill with one of your trigger phrases — does Claude invoke it?
3. If `disable-model-invocation: true`, test it with `/skill-name` directly
4. Review the SKILL.md — is it under 200 lines?
5. Is detailed content in `references/` rather than inline?