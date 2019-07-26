PalletTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_EventScript_SpokeWithGirl
	.byte 0

PalletTown_EventScript_SpokeWithGirl:
	setvar VAR_INFLAG1, 3
	setobjectxyperm 1, 3, 10
	setobjectmovementtype 1, MOVEMENT_TYPE_WANDER_AROUND
	end

PalletTown_EventScript_MCsHouseSign::
	msgbox PalletTown_Text_MCsHouseSign, MSGBOX_SIGN
	end

PalletTown_EventScript_RivalsHouseSign::
	msgbox PalletTown_Text_RivalsHouseSign, MSGBOX_SIGN
	end

PalletTown_EventScript_OaksLab::
	msgbox PalletTown_Text_OaksLab, MSGBOX_SIGN
	end

PalletTown_EventScript_TrainerTips::
	msgbox PalletTown_Text_TrainerTips, MSGBOX_SIGN
	setvar VAR_INFLAG1, 2
	end

PalletTown_EventScript_Description::
	msgbox PalletTown_Text_Description, MSGBOX_SIGN
	end

PalletTown_Girl::
	lock
	compare VAR_INFLAG1, 2
	goto_if_eq PalletTown_Girl3
	compare VAR_INFLAG1, 3
	goto_if_eq PalletTown_Girl4
	compare VAR_INFLAG1, 1
	goto_if_eq PalletTown_Girl2
	msgbox PalletTown_Text_Girl1, MSGBOX_DEFAULT
	applymovement 1, PalletTown_GirlMovement1
	waitmovement 0
	msgbox PalletTown_Text_Girl2, MSGBOX_DEFAULT
	applymovement 1, PalletTown_GirlMovement2
	waitmovement 0
	setvar VAR_INFLAG1, 1
	release
	end
PalletTown_Girl2:
	msgbox PalletTown_Text_Girl3, MSGBOX_DEFAULT
	release
	end
PalletTown_Girl3:
	faceplayer
	msgbox PalletTown_Text_Girl4, MSGBOX_DEFAULT
	release
	end
PalletTown_Girl4:
	lock
	faceplayer
	msgbox PalletTown_Text_Girl5, MSGBOX_DEFAULT
	release
	end

PalletTown_FatMan::
	lock
	faceplayer
	msgbox PalletTown_Text_FatMan, MSGBOX_DEFAULT
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
