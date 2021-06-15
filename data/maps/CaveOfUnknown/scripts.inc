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
	setvar VAR_0x8000, MUGSHOT_ROY
	callnative DrawMugshot
	msgbox CaveofUnknown_Text_ConfusedMale, MSGBOX_DEFAULT
	callnative ClearMugshot
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
	setvar VAR_0x8000, MUGSHOT_ROY
	callnative DrawMugshot
	msgbox CaveofUnknown_Text_GoingCrazyMale, MSGBOX_DEFAULT
	callnative ClearMugshot
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
	setvar VAR_0x8000, MUGSHOT_ROY
	callnative DrawMugshot
	msgbox CaveofUnknown_Text_GoingCrazyMale2, MSGBOX_DEFAULT
	callnative ClearMugshot
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
	msgbox CaveofUnknown_HeadedHome, MSGBOX_DEFAULT
	fadescreen 3
	fadescreen 2
	msgbox CaveofUnknown_Text_WhatsHappening, MSGBOX_DEFAULT
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
	setvar VAR_0x8000, MUGSHOT_ROY
	callnative DrawMugshot
	msgbox CaveofUnknown_Text_HeadedHomeMale, MSGBOX_DEFAULT
	callnative ClearMugshot
	fadescreen 3
	fadescreen 2
	callnative DrawMugshot
	msgbox CaveofUnknown_Text_WhatsHappeningMale, MSGBOX_DEFAULT
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
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GREY}Wh-Where am I?\p"
	.string "Wasn't I just on my way to my room?$"

CaveofUnknown_Text_ConfusedMale:
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GREY}What the hell's going on?\p"
	.string "I could've sworn I was in my room.$"

CaveofUnknown_Text_HeadedHomeFemale:
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GREY}Looks like I might be able\n"
	.string "to get home this way.\p"
	.string "...\p"

CaveofUnknown_Text_WhatsHappening:
	.string "She...sha.....ve..us...al..\p"
	.string "...\p"
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GREY}What the hell's happening to me?\p"
	.string "WHOOOOOOOOAAAAAAA!!!$"

CaveofUnknown_Text_HeadedHomeMale:
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GREY}I think I finally found the\n"
	.string "way back home.\p"
	.string "...$"

CaveofUnknown_Text_WhatsHappeningMale:
	.string "He...sha.....ve..us...al..\p"
	.string "...\p"
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GREY}Wh-What the fuck is going on right\n" 
	.string "now?\p"
	.string "AAAAHHHHHHHHH!!!$"

CaveofUnknown_Text_GoingCrazyFemale:
	.string "...........{PLAYER}........\p"
	.string "You can hear some calling your name\n"
	.string "in the distance.\p"
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GREY}I must be going crazy.$"

CaveofUnknown_Text_GoingCrazyMale:
	.string ".........{PLAYER}........\p"
	.string "You can hear someone calling your name\n"
	.string "in the distance.\p"
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GREY}Look at this I'm already hearing\n"
	.string "things.$"

CaveofUnknown_Text_GoingCrazyFemale2:
	.string "{PLAYER}.......{PLAYER}......\p"
	.string "You can once again hear someone calling\n"
	.string "your name in the distance.\p"
	.string "{COLOR RED}{PLAYER}:{COLOR DARK_GREY}Again!?\n"
	.string "I need to get out of here quick.$"

CaveofUnknown_Text_GoingCrazyMale2:
	.string "{PLAYER}.......{PLAYER}......\p"
	.string "You can once again hear someone calling\n"
	.string "your name in the distance.\p"
	.string "{COLOR BLUE}{PLAYER}:{COLOR DARK_GREY}Not Again!!\n"
	.string "I need to leave here quickly.$"



