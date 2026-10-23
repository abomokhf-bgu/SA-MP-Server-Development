# SA-MP Roleplay Server — Project Archive

**Project owner, host, and development coordinator:** Fadi Abomokh (known in the server as **Max Conway**)  
**Status:** Private portfolio preparation; collaborative, existing codebase.

## Project overview
This repository documents a San Andreas Multiplayer (SA-MP) roleplay server and its associated community operations. The server used Pawn scripts and was developed collaboratively on top of an existing codebase.

## My role
I represented myself in Project Roleplay under the in-game/server identity **Max Conway**. As the **server owner and host**, I was responsible for hosting the server and coordinating its operation. As the **development coordinator**, I set project direction, prepared feature requirements and developer to-do lists, assigned development tasks, coordinated developers and administrators, and participated in some Pawn scripting and testing. I was **not** the primary programmer or sole author of the server code.

## vBulletin 4 forum
I independently installed and set up the project's vBulletin 4 community forum. This describes deployment and configuration of an existing forum platform, **not** authorship of vBulletin software. Additional forum documentation is available in [docs/forum/README.md](docs/forum/README.md). Screenshots are retained separately for privacy review; licensed forum software is not included.

## Repository layout
- `gamemodes/` — existing Pawn gamemode and supporting systems
- `filterscripts/` — additional server scripts
- `include/` — third-party Pawn includes and dependencies (licenses require separate review)
- Database dumps and server configuration are deliberately excluded from this archive.
- Personalized donor scripts and historical working copies are excluded pending permission and privacy review.

## Attribution and licensing
The existing MIT license retains the original **2020 ShadowOG69** copyright notice. Ownership of the server project does not transfer copyright in the original codebase. Other contributors and third-party components retain their own rights. This archive does not imply that Max Conway wrote every included file.

## Security and release notes
The RCON password and database credentials in this prepared archive use placeholders. Do not use these placeholders in a live deployment. Rotate any previously exposed real credentials. Before making this repository public, inspect all scripts, SQL records, server addresses, embedded tokens, third-party binaries, and licenses. The code has not been compiled or verified to run.
