DewfordTown_House1_MapScripts:: @ 81FC3CD
	.byte 0

DewfordTown_House1_EventScript_Man:: @ 81FC3CE
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman:: @ 81FC3D7
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon:: @ 81FC3E0
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland: @ 81FC3F3
	.string "There's a lot to be said for living in\n"
	.string "a small town like this in harmony with\l"
	.string "POKéMON and the family.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland: @ 81FC45B
	.string "I left the major port of Alantia\n"
	.string "City when I married my husband here.\p"
	.string "Life goes by slowly in this little\n"
	.string "town. But being surrounded by the\l"
	.string "eyesore of a desert--that's painful, too.$"

DewfordTown_House1_Text_Zigzagoon: @ 81FC510
	.string "ZIGZAGOON: Guguuh!$"

