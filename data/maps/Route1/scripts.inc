Route1_MapScripts::
	.byte 0

Route1_EventScript_Sign::
	msgbox Route1_Text_Sign, MSGBOX_SIGN
	end

Route1_MartEmployee::
	lock
	faceplayer
	compare VAR_INFLAG1, 4
	goto_if_ge Route1_MartEmployee2
	msgbox Route1_Text_MartEmployee, MSGBOX_DEFAULT
	giveitem ITEM_POTION, 1
	setvar VAR_INFLAG1, 4
	release
	end
Route1_MartEmployee2:
	msgbox Route1_Text_MartEmployee2, MSGBOX_DEFAULT
	release
	end

Route1_LedgeGuy::
	lock
	faceplayer
	msgbox Route1_Text_LedgeGuy, MSGBOX_DEFAULT
	release
	end

Route1_Youngster::
	lock
	faceplayer
	msgbox Route1_Text_Youngster, MSGBOX_DEFAULT
	release
	end

Route1_Text_Sign:
	.string "ROUTE 1\n"
	.string "PALLET TOWN - VIRIDIAN CITY$"

Route1_Text_MartEmployee:
	.string "Hi!\n"
	.string "I work at a POKéMON MART.\p"
	.string "It's part of a convenient chain\n"
	.string "selling all sorts of items.\p"
	.string "Please, visit us in VIRIDIAN CITY.\p"
	.string "I know, I'll give you a sample.\n"
	.string "Here you go!$"

Route1_Text_MartEmployee2:
	.string "Please come see us if you need\n"
	.string "POKé BALLS for catching POKéMON.$"

Route1_Text_LedgeGuy:
	.string "See those ledges along the road?\p"
	.string "It's a bit scary, but you can jump\n"
	.string "from them.\p"
	.string "You can get back to PALLET TOWN\n"
	.string "quicker that way.$"

Route1_Text_Youngster:
	.string "You've got a pretty sweet POKéMON\n"
	.string "with you!\p"
	.string "I'll bring along my favorite POKéMON\n"
	.string "later, so you'd better battle me when\l"
	.string "I do!$"
