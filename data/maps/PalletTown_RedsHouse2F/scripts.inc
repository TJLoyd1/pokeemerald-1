PalletTown_RedsHouse2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RedsHouse2F_EventScript_WakeUp
	.byte 0

RedsHouse2F_EventScript_WakeUp::
    map_script_2 VAR_0x402E, 0, RedsHouse2F_EventScript_GetUp
	.2byte 0

RedsHouse2F_EventScript_GetUp::
	compare VAR_0x402E, 1
	goto_if_eq RedsHouse2F_EventScript_End
	lockall
	msgbox PalletTown_RedsHouse2F_Mother, MSGBOX_DEFAULT
	setvar VAR_0x402E, 1
	releaseall
	end

RedsHouse2F_EventScript_End::
	end

RedsHouse2F_EventScript_DoIt::
	lockall
	checkflag FLAG_SET_WALL_CLOCK
	goto_if_set FLAG_SET_WALL_CLOCK, RedsHouse2F_EventScript_End
	applymovement 0xFF, PalletTown_RedsHouse2F_NoClock
	waitmovement 0
	msgbox PalletTown_RedsHouse2F_Text_DoIt, MSGBOX_DEFAULT
	releaseall
	end

PalletTown_RedsHouse2F_SetClock::
	lockall
	checkflag FLAG_SET_WALL_CLOCK
	goto_if_set FLAG_SET_WALL_CLOCK, PalletTown_RedsHouse2F_CheckClock
	msgbox PalletTown_RedsHouse2F_Text_SetClock, MSGBOX_DEFAULT
	fadescreen 1
	special StartWallClock
	waitstate
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
	setflag FLAG_SET_WALL_CLOCK
	releaseall
	end

PalletTown_RedsHouse2F_CheckClock::
	incrementgamestat 45
	fadescreen 1
	special Special_ViewWallClock
	waitstate
	releaseall
	end

PalletTown_RedsHouse2F_GameCube::
	msgbox RedsHouse2F_Text_GameCube, MSGBOX_SIGN
	end

PalletTown_RedsHouse2F_Notebook::
	msgbox PalletTown_RedsHouse2F_Text_Notebook, MSGBOX_SIGN
	end

PalletTown_RedsHouse2F_NoClock::
	walk_down
	step_end

PalletTown_RedsHouse2F_Text_DoIt:
	.string "I haven't set the clock yet.$"

PalletTown_RedsHouse2F_Text_SetClock:
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"

PalletTown_RedsHouse2F_Mother:
	.string "MOM: {PLAYER}, are you awake yet?\n"
	.string "Get going, sweetie!\l"
	.string "Today is your big day!\p"
	.string "Oh, and don't forget to check the\n"
	.string "clock your father bought for you.$"

RedsHouse2F_Text_GameCube:
	.string "It's a Nintendo GameCube.\p"
	.string "A Game Boy Advance is connected to\n"
	.string "serve as the Controller.$"

PalletTown_RedsHouse2F_Text_Notebook:
	.string "{PLAYER} flipped open the notebook.\p"
	.string "ADVENTURE RULE NO. 1\n"
	.string "Open the MENU with START.\p"
	.string "ADVENTURE RULE NO. 2\n"
	.string "Record your progress with SAVE.\p"
	.string "The remaining pages are blank…$"
