CaveOfUnknown_MapScripts::
	.byte 0

CaveofUnknown_EventScript::
	lock
	setvar VAR_UNKNOWNCAVE, 1
	applymovement OBJ_EVENT_ID_PLAYER, CaveofUnknown_LookAround
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq CaveofUnknown_EventScript_ConfusedMale
	msgbox CaveofUnknown_Text_ConfusedFemale, MSGBOX_DEFAULT
	release
	end
	
CaveofUnknown_EventScript_ConfusedMale::
	lock
	msgbox CaveofUnknown_Text_ConfusedMale, MSGBOX_DEFAULT
	release
	end

CaveofUnknown_EventScript_HearingThings::
	lock
	setvar VAR_NAME_CALLED_ONCE, 1
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq CaveofUnknown_EventScript_HearingThingsMale
	applymovement OBJ_EVENT_ID_PLAYER, CaveofUnknown_DownLeft
	msgbox CaveofUnknown_Text_GoingCrazyFemale, MSGBOX_DEFAULT
	waitmovement 0
	release
	end

CaveofUnknown_EventScript_HearingThingsMale::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CaveofUnknown_DownLeft
	msgbox CaveofUnknown_Text_GoingCrazyMale, MSGBOX_DEFAULT
	waitmovement 0
	release
	end

CaveofUnknown_EventScript_HearingThingsAgain::
	lock
	setvar VAR_NAME_CALLED_TWICE, 1
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq CaveofUnknown_EventScript_HearingThingsAgainMale
	applymovement OBJ_EVENT_ID_PLAYER, CaveofUnknown_RightDown
	msgbox CaveofUnknown_Text_GoingCrazyFemale2, MSGBOX_DEFAULT
	waitmovement 0
	release
	end

CaveofUnknown_EventScript_HearingThingsAgainMale::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CaveofUnknown_RightDown
	msgbox CaveofUnknown_Text_GoingCrazyMale2, MSGBOX_DEFAULT
	waitmovement 0
	release
	end

CaveofUnknown_EventScript_HeadedHome::
	lock
	setvar VAR_AWOKEN_FROM_DREAM, 1
	applymovement OBJ_EVENT_ID_PLAYER, CaveofUnknown_HeadedHome
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq CaveofUnknown_EventScript_HeadedHomeMale
	msgbox CaveofUnknown_Text_HeadedHomeFemale, MSGBOX_DEFAULT
	fadescreen 3
	fadescreen 2
	fadescreen 3
	fadescreen 2
	warp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 255, 7, 4
	applymovement OBJ_EVENT_ID_PLAYER, CaveofUnknown_BackHomeFemale
	waitmovement 0
	setflag FLAG_AWOKE_FROM_DREAM
	waitstate
	release
	end

CaveofUnknown_EventScript_HeadedHomeMale::
	msgbox CaveofUnknown_Text_HeadedHomeMale, MSGBOX_DEFAULT
	fadescreen 3
	fadescreen 2
	fadescreen 3
	fadescreen 2
	warp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 255, 7, 4
	applymovement OBJ_EVENT_ID_PLAYER, CaveofUnknown_BackHomeMale
	waitmovement 0
	setflag FLAG_AWOKE_FROM_DREAM
	waitstate
	release
	end
	
CaveofUnknown_LookAround:
	face_left
	delay_16
	delay_8
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_up
	step_end

CaveofUnknown_DownLeft:
	face_down
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	step_end

CaveofUnknown_RightDown:
	face_right
	delay_16
	delay_8
	face_down
	delay_16
	delay_8
	face_up
	step_end

CaveofUnknown_HeadedHome:
	face_left
	delay_16
	delay_8
	face_right
	delay_16
	delay_8
	face_up
	step_end
	
CaveofUnknown_BackHomeFemale:
	face_left
	delay_16
	face_right
	delay_16
	walk_left
	walk_left
	delay_8
	face_up
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	step_end

CaveofUnknown_BackHomeMale:
	face_right
	delay_16
	face_left
	delay_16
	walk_right
	walk_right
	delay_8
	face_up
	delay_16
	face_down
	delay_16
	face_right
	delay_16
	step_end

CaveofUnknown_Text_ConfusedFemale:
	.string "{PLAYER}:{COLOR RED}Wh-Where am I?\p"
	.string "{COLOR RED}Wasn't I just on my way to my room?$"

CaveofUnknown_Text_ConfusedMale:
	.string "{PLAYER}:{COLOR BLUE}What the hell's going on?\p"
	.string "{COLOR BLUE}I could've sworn I was in my room.$"

CaveofUnknown_Text_HeadedHomeFemale:
	.string "{PLAYER}:{COLOR RED}Looks like I might be able\n"
	.string "{COLOR RED}to get home this way.\p"
	.string "{COLOR RED}...\p"
	.string "{COLOR RED}What the hell's happening to me?\p"
	.string "{COLOR RED}WHOOOOOOOOAAAAAAA!!!$"

CaveofUnknown_Text_HeadedHomeMale:
	.string "{PLAYER}:{COLOR BLUE}I think I finally found the\n"
	.string "{COLOR BLUE}way back home.\p"
	.string "{COLOR BLUE}...\p"
	.string "{COLOR BLUE}Wh-What the fuck is going on right now?\p"
	.string "{COLOR BLUE}AAAAHHHHHHHHH!!!$"

CaveofUnknown_Text_GoingCrazyFemale:
	.string "...........{PLAYER}........\p"
	.string "You can hear some calling your name\n"
	.string "in the distance.\p"
	.string "{PLAYER}:{COLOR RED}I must be going crazy.$"

CaveofUnknown_Text_GoingCrazyMale:
	.string ".........{PLAYER}........\p"
	.string "You can hear someone calling your name\n"
	.string "in the distance.\p"
	.string "{PLAYER}:{COLOR BLUE}Look at this I'm already hearing\n"
	.string "{COLOR BLUE}things.$"

CaveofUnknown_Text_GoingCrazyFemale2:
	.string "{PLAYER}.......{PLAYER}......\p"
	.string "You can once again hear someone calling\n"
	.string "your name in the distance.\p"
	.string "{PLAYER}:{COLOR RED}Again!?\n"
	.string "{COLOR RED}I need to get out of here quick.$"

CaveofUnknown_Text_GoingCrazyMale2:
	.string "{PLAYER}.......{PLAYER}......\p"
	.string "You can once again hear someone calling\n"
	.string "your name in the distance.\p"
	.string "{PLAYER}:{COLOR BLUE}Not Again!!\n"
	.string "{COLOR BLUE}I need to leave here quickly.$"
	