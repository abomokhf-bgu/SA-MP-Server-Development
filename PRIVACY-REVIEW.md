# Publication review

This repository is an archive of the Project Roleplay SA-MP server, not a runnable or security-audited release.

## Already done

- Removed the original database dumps and private server configuration from the current project snapshot.
- Excluded some historical working copies and personalized donor scripts.
- Replaced a historical hard-coded external IP address in the current gamemode snapshot with a localhost-only check.
- Kept the original license notice and existing author comments.
- Added forum screenshots and documentation showing the community side of the project.

## Before making the source public

- **Code permissions:** Confirm that the original codebase, contributions by other developers, mapping assets, and bundled Pawn dependencies can be redistributed. The top-level MIT license is not proof that every included file has the same license.
- **Full Git history:** Review earlier commits, not just the current files. Previously committed credentials or private data remain accessible in Git history even after being deleted from the latest version.
- **Secrets:** Run a full-history secrets scan and rotate any credentials that might have been exposed. Check old server passwords, database connections, tokens, addresses, and personal details.
- **Community privacy:** Review screenshots and source comments for real names, account data, or details that should not be shared.
- **Build:** Dependencies and runtime files are incomplete. The code has not been compiled or tested as a complete server.

## Current review scope

The current repository tree and documentation were checked for obvious publication problems, including filenames associated with database exports and credentials. Selected Pawn source files were also inspected. **This was not a complete line-by-line audit of the entire codebase or its commit history.** No claim of publication safety is made.

Keep the full source archive private until redistribution rights and historical secrets have been reviewed. A public portfolio containing only original documentation, approved screenshots, and code samples you are allowed to share is a lower-risk alternative.
