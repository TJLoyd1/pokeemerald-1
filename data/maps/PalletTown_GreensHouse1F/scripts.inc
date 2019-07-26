PalletTown_GreensHouse1F_MapScripts::
	.byte 0

PalletTown_GreensHouse1F_Daisy::
	msgbox PalletTown_GreensHouse1F_Text_Daisy, MSGBOX_NPC
	end

PalletTown_GreensHouse1F_Box::
	msgbox PalletTown_GreensHouse1F_Text_Box, MSGBOX_NPC
	end

PalletTown_GreensHouse1F_Text_Daisy:
	.string "DAISY: Hi, {PLAYER}!\p"
	.string "My brother, {RIVAL}, is out at\n"
	.string "Grandpa's LAB.$"

PalletTown_GreensHouse1F_Text_Box:
	.string "It's a tightly closed box.\p"
	.string "I wonder what's inside…$"
