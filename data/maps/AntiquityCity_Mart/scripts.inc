AntiquityCity_Mart_MapScripts::
	.byte 0

AntiquityCity_Mart_EventScript_Clerk:: @ 8214F06
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_unset FLAG_BADGE01_GET, AntiquityCity_Mart_EventScript_PokemartBasic
	goto_if_set FLAG_BADGE01_GET, AntiquityCity_Mart_EventScript_PokemartExpanded
	end

AntiquityCity_Mart_EventScript_PokemartBasic:: @ 8214F21
	pokemart AntiquityCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

AntiquityCity_Mart_Pokemart_Basic: @ 8214F30
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_NONE
	release
	end

AntiquityCity_Mart_EventScript_PokemartExpanded:: @ 8214F48
	pokemart AntiquityCity_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
AntiquityCity_Mart_Pokemart_Expanded: @ 8214F58
	.2byte ITEM_POKE_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_NONE
	release
	end

AntiquityCity_Mart_EventScript_Hiker:: @ 8214F74
	msgbox AntiquityCity_Mart_Text_BuyingBallsInCaseOfHippopotas, MSGBOX_NPC
	end

AntiquityCity_Mart_EventScript_Girl:: @ 8214F7D
	msgbox AntiquityCity_Mart_Text_ShouldBuyRevivesInstead, MSGBOX_NPC
	end

AntiquityCity_Mart_Text_BuyingBallsInCaseOfHippopotas: @ 8214F8F
	.string "I'm buying some POKéBALLS and\n"
	.string "POTIONS.\p"
	.string "Just in case I run into HIPPOPOTAS\n"
	.string "in GRANITE CAVE.$"

AntiquityCity_Mart_Text_ShouldBuyRevivesInstead: @ 8214FF1
	.string "My POKéMON fainted again.\n"
	.string "It has a lot of HP but low DEFENSE.\p"
	.string "I should buy REVIVES for it\n"
	.string "instead of ordinary POTIONS.$"

