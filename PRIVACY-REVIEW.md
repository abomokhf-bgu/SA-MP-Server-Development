# Publication review

Project Roleplay is a historical SA-MP source archive, not a tested or security-audited server release.

## Checks performed (23 October 2026)

- Inspected the repository's complete current file inventory: **483 tracked files** at the time of review.
- Checked filenames for common database dumps, private keys, environment files, and configuration exports. No obvious files with those extensions were found in the current tree.
- Inspected over 100 readable project and documentation files, including account-handling, jobs, properties, vehicles, factions, staff systems, and filterscripts.
- Searched inspected text for common patterns associated with embedded secrets, private-key blocks, Discord webhooks, email addresses, and IPv4 addresses. **No clear live secret was identified by these checks.**
- Inspected commit metadata and selected available diffs, including the original source-upload commit.
- Verified the current project documentation and forum screenshot references.

## Limits of the scan

**This is not a complete clean result.** The GitHub connection did not return the full content of several large source files, including `gamemodes/PRP.pwn`, `filterscripts/server_maps.pwn`, and `filterscripts/donorMaps.inc`. Some historical commit diffs are incomplete. Pattern matching also misses secrets that use unusual names or formats. The bundled third-party libraries were not all audited line by line.

A removed secret can still exist in an earlier Git commit. No complete full-history scan or credential validation was performed.

## Before publishing the full source

1. **Permissions:** Confirm the right to redistribute the existing Pawn codebase, other developers' contributions, map assets, and bundled third-party dependencies. The top-level MIT notice is not automatically a license for every file.
2. **Local full-history scan:** Clone the repository on a trusted machine and run a dedicated scanner such as Gitleaks against all commits. Investigate findings without publishing any detected secrets.
3. **Large source files:** Inspect the three large files named above, plus any other files omitted by the connected review, for credentials, addresses, personal data, and third-party ownership.
4. **Credentials:** Rotate any historical server, database, or service credentials that may still be active.
5. **Screenshots:** Review visible usernames, avatars, and member information before making the repository public.
6. **Build:** Treat the archive as non-runnable unless dependencies and configuration are restored and a build is verified.

The original database and private server configuration were excluded from the current source snapshot. Some historical working copies and personalized donor scripts were also excluded. This does not establish that previous commits are free of sensitive data.

**Recommendation:** Keep the full source repository private until the permission and full-history checks are complete. A separate public portfolio with documentation, reviewed screenshots, and approved code excerpts is a safer option.
