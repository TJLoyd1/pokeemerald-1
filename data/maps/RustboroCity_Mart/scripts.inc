RustboroCity_Mart_MapScripts:: @ 8214F05
	map_script MAP_SCRIPT_ON_LOAD, RustboroCity_Mart_OnLoad
	.byte 0

RustboroCity_Mart_OnLoad:
	call_if_unset FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_HideSpecialBallsSeller
RustboroCity_Mart_OnLoad_End:
	end

RustboroCity_Mart_HideSpecialBallsSeller:
	goto_if_set FLAG_HIDE_SPECIAL_BALLS_SELLER, RustboroCity_Mart_OnLoad_End
	setflag FLAG_HIDE_SPECIAL_BALLS_SELLER
	return

RustboroCity_Mart_EventScript_PokefanF:: @ 8214F74
	msgbox RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_Boy:: @ 8214F7D
	msgbox RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead, MSGBOX_NPC
	end

RustboroCity_Mart_EventScript_BugCatcher:: @ 8214F86
	msgbox RustboroCity_Mart_Text_GettingEscapeRopeJustInCase, MSGBOX_NPC
	end

RustboroCity_Mart_Text_BuyingHealsInCaseOfShroomish: @ 8214F8F
	.string "I'm buying some PARLYZ HEALS and\n"
	.string "ANTIDOTES.\p"
	.string "Just in case I run into SHROOMISH\n"
	.string "in PETALBURG WOODS.$"

RustboroCity_Mart_Text_ShouldBuySuperPotionsInstead: @ 8214FF1
	.string "My POKéMON evolved.\n"
	.string "It has a lot of HP now.\p"
	.string "I should buy SUPER POTIONS for it\n"
	.string "instead of ordinary POTIONS.$"

RustboroCity_Mart_Text_GettingEscapeRopeJustInCase: @ 821505C
	.string "I'm getting an ESCAPE ROPE just in\n"
	.string "case I get lost in a cave.\p"
	.string "I just need to use it to get back to\n"
	.string "the entrance.$"

