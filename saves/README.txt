TUROK: RAGE WARS (Windows port) - Controller Pak saves
=======================================================

This folder holds the "virtual Controller Paks" (the N64 memory cards) of the port.  The game saves its player
profiles here exactly as it would on a real Controller Pak: through its own menus (1 PLAYER TRIALS -> CREATE PLAYER,
CONTROLLER PAK -> DELETE PLAYERS ...).  A profile is a note called "RAGE WARS.<name>" and needs 7 free pages
(1792 bytes) and one of the 16 note slots of the pak.

FILES
  Turok; Rage Wars_Cont_1.mpk    the pak in controller port 1 (the one the 1-player game uses)
  Turok; Rage Wars_Cont_2.mpk    port 2   (_Cont_3 and _Cont_4: ports 3 and 4, used in multiplayer)
  <file>.orig                    the original of a damaged / too short file, kept once before the game repaired it

Every file is a normal 32768-byte Controller Pak image (the .mpk format of Project64, mupen64plus, MPK Manager ...).
A file is created, freshly formatted and empty, the first time its port is used.  Nothing is saved anywhere else.

BACKUP / MOVING A SAVE
  Copy the .mpk file (closing the game first is safest: changes are written about 0.3 s after the game makes
  them and at exit).  Saves from Project64 2.x / 3.x work as they are: copy "Turok; Rage Wars_Cont_1.mpk" (what
  Project64 calls the Controller Pak file of the game, from its Save folder or from the game's own sub folder there)
  into this folder, or tell the port where Project64's Save folder is (TUROK_PJ64_SAVE or "pj64_save" in the ini).
  Paks saved by the port can be opened by Project64 the same way.  Other containers are read and written back
  in place: DexDrive .n64, 4-in-1 .mpk (mupen64plus; port N uses the Nth pak of the file), and a pak file with
  trailing data (MPK Manager comments).  The game never touches notes of other games on a shared pak.

SETTINGS (all optional)
  Next to the exe, "turok_pak.ini" (copy turok_pak.ini.sample from this folder and edit it), or environment variables:
    TUROK_SAVEDIR=<folder>        where the paks are kept (default: "saves" next to the exe)
    TUROK_PAK1=<file> .. TUROK_PAK4=<file>   an explicit image for a port ("file.mpk#2" = 2nd pak of a 4-in-1 file)
    TUROK_PJ64_SAVE=<folder>      use the paks of this Project64 Save folder when it has them
    TUROK_PAK1_TYPE=none|memory|rumble  (.. _TYPE4)   what is plugged into a controller at start-up; default: a
                                  memory pak in every port.  A rumble pak makes the pad vibrate (XInput pads).
    TUROK_PAK=0                   no pak at all (the game then says NO CONTROLLER PAK FOUND, nothing is saved)

WHILE PLAYING  (game window in front; "hotkeys = 0" in the ini switches the keys off)
  Ctrl+F5 .. Ctrl+F8             pull out / push in the memory pak of controller 1 .. 4
  Ctrl+Shift+F5 .. F8            the same with a rumble pak
  The game notices the change the way it does on a console, when it next looks at the pak: pull the pak out and
  open 1 PLAYER TRIALS -> NO CONTROLLER PAK FOUND; push it in again and choose RETRY.  (A script can do the same with a
  file port_pak.txt: "remove 1", "insert 1 memory", "insert 1 rumble", "format 1", "reload 1", "flush", "status".)

IF SOMETHING IS WRONG
  DAMAGED CONTROLLER PAK in the game: choose ATTEMPT REPAIR (the game's own repair; it may lose notes it cannot read).
  The original file is kept as <name>.mpk.orig.
  Read-only file, locked file, or a save folder that cannot be created: the game still works, but that pak lives in
  memory only (the log, port_log.txt in the working directory or the file named by TUROK_LOG, says "NOT SAVED" and why).
  Tools: python tools\pak_tool.py info <file>  checks a pak image and lists its notes (more in docs\PORT_STATUS.md).
