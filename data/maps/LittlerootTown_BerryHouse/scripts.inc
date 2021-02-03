LittlerootTown_BerryHouse_MapScripts::
	.byte 0

LittlerootTown_BerryHouse_Script_FreeBerries::
	lock
	faceplayer
	msgbox Text_OranBerries, MSGBOX_DEFAULT
	checkitem ITEM_ORAN_BERRY, 3
	compare VAR_RESULT, 1
	goto_if_ge Script_HasBerriesAlready
	msgbox Text_GivingBerries, MSGBOX_DEFAULT
	giveitem ITEM_ORAN_BERRY, 3
	compare VAR_RESULT, 0
	goto_if_eq Script_BagIsFull
	release
	end

Script_HasBerriesAlready::
	msgbox Text_HasBerriesAlready, MSGBOX_DEFAULT
	release
	end

Script_BagIsFull::
	msgbox Text_BagIsFull, MSGBOX_DEFAULT
	release
	end

Text_OranBerries:
	.string "I found these while I was out hiking one\n"
	.string "day.$"
	
Text_GivingBerries:
	.string "Here you go!$"

Text_HasBerriesAlready:
	.string "Those were the only ones I found.\p"
	.string "Sorry.$"

Text_BagIsFull:
	.string "Your BAG is full.$"