PalletTown_MapScripts::
	.byte 0

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
	end

PalletTown_EventScript_Description::
	msgbox PalletTown_Text_Description, MSGBOX_SIGN
	end

PalletTown_Text_OaksLab:
	.string "OAK POKéMON RESEARCH LAB$"

PalletTown_Text_MCsHouseSign:
	.string "{PLAYER}'s HOUSE$"

PalletTown_Text_RivalsHouseSign:
	.string "{RIVAL}'s HOUSE$"

PalletTown_Text_TrainerTips:
	.string "TRAINER TIPS\n"
	.string "Press START to open the menu!$"

PalletTown_Text_Description:
	.string "PALLET TOWN\n"
	.string "“Shades of your journey await!”$"
