PalletTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_EventScript_SpokeWithGirl
	.byte 0

PalletTown_EventScript_SpokeWithGirl:
	call_if_set FLAG_SPOKE_WITH_GIRL, PalletTown_EventScript_ReallySpokeWithGirl
	end

PalletTown_EventScript_ReallySpokeWithGirl:
	setflag FLAG_GIRL_RAISING
	setvar VAR_TRAINER_TIPS, 0
	setobjectxyperm 1, 3, 10
	setobjectmovementtype 1, MOVEMENT_TYPE_WANDER_AROUND
	return

PalletTown_EventScript_MCsHouseSign::
	lockall
	msgbox PalletTown_Text_MCsHouseSign, MSGBOX_DEFAULT
	releaseall
	end

PalletTown_EventScript_RivalsHouseSign::
	lockall
	msgbox PalletTown_Text_RivalsHouseSign, MSGBOX_DEFAULT
	releaseall
	end

PalletTown_EventScript_OaksLab::
	msgbox PalletTown_Text_OaksLab, MSGBOX_SIGN
	end

PalletTown_EventScript_TrainerTips::
	msgbox PalletTown_Text_TrainerTips, MSGBOX_SIGN
	setvar VAR_TRAINER_TIPS, 1
	end

PalletTown_EventScript_Description::
	msgbox PalletTown_Text_Description, MSGBOX_SIGN
	end

PalletTown_Girl::
	lock
	compare VAR_TRAINER_TIPS, 1
	goto_if_eq PalletTown_Girl3
	checkflag FLAG_GIRL_RAISING
	vgoto_if 1, PalletTown_Girl4
	checkflag FLAG_SPOKE_WITH_GIRL
	vgoto_if 1, PalletTown_Girl2
	msgbox PalletTown_Text_Girl1, MSGBOX_SIGN
	applymovement 1, PalletTown_GirlMovement1
	waitmovement 0
	msgbox PalletTown_Text_Girl2, MSGBOX_SIGN
	applymovement 1, PalletTown_GirlMovement2
	waitmovement 0
	setflag FLAG_SPOKE_WITH_GIRL
	release
	end
PalletTown_Girl2:
	msgbox PalletTown_Text_Girl3, MSGBOX_SIGN
	release
	end
PalletTown_Girl3:
	faceplayer
	msgbox PalletTown_Text_Girl4, MSGBOX_SIGN
	release
	end
PalletTown_Girl4:
	lock
	faceplayer
	msgbox PalletTown_Text_Girl5, MSGBOX_SIGN
	release
	end

PalletTown_FatMan::
	lock
	faceplayer
	msgbox PalletTown_Text_FatMan, MSGBOX_SIGN
	release
	end

PalletTown_GirlMovement1:
	face_right
	emote_exclamation_mark
	step_end

PalletTown_GirlMovement2:
	walk_left
	face_right
	step_end

PalletTown_Text_OaksLab:
	.string "OAK POKéMON RESEARCH LAB$"

PalletTown_Text_MCsHouseSign:
	.string "{PLAYER}'s HOUSE$"

PalletTown_Text_RivalsHouseSign:
	.string "{RIVAL}'s HOUSE$"

PalletTown_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Press START to open the MENU!$"

PalletTown_Text_Description:
	.string "PALLET TOWN\n"
	.string "“Shades of your journey await!”$"

PalletTown_Text_Girl1:
	.string "Hmm…\n"
	.string "Is that right…$"

PalletTown_Text_Girl2:
	.string "Oh!\n"
	.string "Look, look!$"

PalletTown_Text_Girl3:
	.string "Read it, read it!$"

PalletTown_Text_Girl4:
	.string "Signs are useful, aren't they?$"

PalletTown_Text_Girl5:
	.string "I'm raising POKéMON, too.\p"
	.string "When they get strong, they can\n"
	.string "protect me.$"

PalletTown_Text_FatMan:
	.string "Technology is incredible!\p"
	.string "You can now store and recall items\n"
	.string "and POKéMON as data via PC.$"
