# Project Roleplay (SA-MP)

Project Roleplay was a GTA: San Andreas Multiplayer roleplay server I owned and hosted under the name **Max Conway**. I worked with developers and administrators to maintain the server, plan updates, test features, and keep the community running.

I'm **Fadi Abomokh**, a software engineering student. I've kept this repository as a record of the project and the experience I gained working on it.

## What I worked on

My role covered both the server and its community:

- **Server ownership and hosting:** managed the project and coordinated its day-to-day operation.
- **Development teamwork:** discussed features, organized tasks, tested changes, and contributed to Pawn scripting alongside other developers.
- **Server systems:** worked with the team on features involving administration, factions, gangs/families, vehicles, properties, and other roleplay systems.
- **Community forum:** independently set up and managed the associated vBulletin 4 forum, including its structure and staff/community sections.

The server already had an existing codebase, and several developers contributed to it. **I did not write all of the code in this repository.** The forum was built with vBulletin; my work there was setup, configuration, and management rather than developing the forum software itself.

## Project files

| Location | Contents |
| --- | --- |
| [`gamemodes/`](gamemodes/) | Main Pawn gamemode and supporting systems |
| [`filterscripts/`](filterscripts/) | Additional Pawn scripts and map-related files |
| [`include/`](include/) | Pawn includes and external dependencies |
| [`docs/forum/`](docs/forum/) | Forum background and screenshots |
| [`CONTRIBUTORS.md`](CONTRIBUTORS.md) | Credits and responsibilities |

This is a **historical source archive**, not a ready-to-run server package. The database, private configuration, and some working files are intentionally missing. I haven't verified that the archived code compiles or runs as-is.

## Forum screenshots

The vBulletin forum was a separate part of the project that I handled myself. These are screenshots of the recovered forum:

| Applications and appeals | Staff roster |
| --- | --- |
| ![Application and appeal formats](docs/forum/screenshots/forms.png) | ![Project Roleplay staff roster](docs/forum/screenshots/staff-roster.png) |
| Community and factions | Information and support |
| ![Community and factions](docs/forum/screenshots/community-and-factions.png) | ![Information and support](docs/forum/screenshots/information-and-support.png) |

More context is in the [forum documentation](docs/forum/README.md).

## Credits and notes

The source contains work by multiple developers and third-party authors. I have kept the original copyright notice in [LICENSE](LICENSE); see [CONTRIBUTORS.md](CONTRIBUTORS.md) for the distinction between my role and others' contributions. The top-level license should not be assumed to cover every included third-party file.

The repository has been prepared without the original database or private server configuration, but the source has **not** received a complete security, privacy, or redistribution-rights audit. See [PRIVACY-REVIEW.md](PRIVACY-REVIEW.md) before sharing it publicly.
