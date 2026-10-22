# Source archive privacy review — 2026-10-23

This is a source-only portfolio snapshot, **not a security certification** or a runnable release.

## Review and changes
- Removed all SQL/database dumps and configuration files in the previous sanitization pass.
- Removed personalized donor script folders and historical `gamemodes/todo/` working copies in this pass.
- Removed a hard-coded historical external IPv4 address from `gamemodes/PRP.pwn`, preserving localhost-only NPC checking. This changes the historical behavior and may require reconfiguration.
- Kept original third-party author credits and LICENSE unchanged.
- Rechecked text for IPv4 addresses, email addresses, common API key/token patterns, private-key markers, and credential assignments.

## Remaining risks
- Source still contains game character names, developer handles, URLs, and historical comments; these are not necessarily private but should be checked by someone familiar with the community.
- Third-party source code, includes and mapping contributions may require permission or attribution beyond the top-level MIT license.
- Scans cannot rule out all credentials or private information, especially obfuscated secrets or contextual personal data.
- Before publication, review code ownership, rotate any exposed credentials, and check whether each included third-party component may be redistributed.
- No build or execution testing was performed.
