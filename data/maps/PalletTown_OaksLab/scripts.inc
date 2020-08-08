PalletTown_OaksLab_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, OaksLab_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OaksLab_OnWarp
	.byte 0

OaksLab_OnLoad:
	setobjectxyperm 5, 6, 11
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_UP
	savebgm MUS_RG_OHKIDO
	end

OaksLab_OnWarp:
	map_script_2 VAR_INFLAG2, 1, OaksLab_StartMovement
	.2byte 0

OaksLab_StartMovement:
	applymovement 5, OaksLab_Movement_Oak
	waitmovement 0
	applymovement 255, OaksLab_Movement_Player
	waitmovement 0
	applymovement 4, OaksLab_Movement_RivalFaceUp
	setvar VAR_INFLAG2, 2
	clearflag FLAG_DONT_TRANSITION_MUSIC
	savebgm MUS_DUMMY
	fadedefaultbgm
	goto OaksLab_IntroductionToPokemon

OaksLab_IntroductionToPokemon:
	msgbox OaksLab_Text_RivalIsImpatient
	closemessage
	delay 60
	msgbox OaksLab_Text_OakIsPreparing
	closemessage
	delay 30
	applymovement 4, OaksLab_Movement_RivalWalkFastInPlace
	waitmovement 0
	msgbox OaksLab_Text_RivalIsVeryImpatient
	closemessage
	msgbox OaksLab_Text_OakIsClam
	closemessage
	end

OaksLab_EventScript_GenericAides::
	msgbox OaksLab_Text_GenericAides, MSGBOX_NPC
	end

OaksLab_EventScript_DifferentAide::
	msgbox OaksLab_Text_DifferentAide, MSGBOX_NPC
	end

OaksLab_EventScript_Rival::
	compare VAR_INFLAG2, 3
	goto_if_eq OaksLab_EventScript_RivalsPokemonLooksTougherThanThePlayers
	compare VAR_INFLAG2, 2
	goto_if_eq OaksLab_EventScript_RivalIsAJerk
	msgbox OaksLab_Text_RivalStandingStill, MSGBOX_NPC
	end

OaksLab_EventScript_RivalIsAJerk:
	msgbox OaksLab_Text_RivalCallsYouGreedy, MSGBOX_NPC
	end

OaksLab_EventScript_Oak::
	compare VAR_INFLAG2, 4
	goto_if_eq OaksLab_EventScript_OakSuggestsYouToBattleALot
	compare VAR_INFLAG2, 3
	goto_if_eq OaksLab_EventScript_OakInformsYou
	compare VAR_INFLAG2, 2
	goto_if_eq OaksLab_EventScript_OakTellsYouToChoose
	end

OaksLab_EventScript_OakTellsYouToChoose:
	msgbox OaksLab_Text_OakTellsYouToChoose, MSGBOX_NPC
	end

OaksLab_EventScript_OakInformsYou:
	msgbox OaksLab_Text_OakInformsYou, MSGBOX_NPC
	end

OaksLab_EventScript_OakSuggestsYouToBattleALot:
	msgbox OaksLab_Text_OakSuggestsYouToBattleALot, MSGBOX_NPC
	end

OaksLab_EventScript_BulbasaursPokeBall::
	compare VAR_INFLAG2, 3
	goto_if_eq OaksLab_EventScript_OaksLastPokemon
	compare VAR_INFLAG2, 2
	goto_if_eq OaksLab_EventScript_PlayerInspectsBulbasaursBall
	msgbox OaksLab_Text_TheseArePokeBalls
	closemessage
	end
OaksLab_EventScript_CharmandersPokeBall::
	compare VAR_INFLAG2, 3
	goto_if_eq OaksLab_EventScript_OaksLastPokemon
	compare VAR_INFLAG2, 2
	goto_if_eq OaksLab_EventScript_PlayerInspectsCharmandersBall
	msgbox OaksLab_Text_TheseArePokeBalls
	closemessage
	end
OaksLab_EventScript_SquirtlesPokeBall::
	compare VAR_INFLAG2, 3
	goto_if_eq OaksLab_EventScript_OaksLastPokemon
	compare VAR_INFLAG2, 2
	goto_if_eq OaksLab_EventScript_PlayerInspectsSquirtlesBall
	msgbox OaksLab_Text_TheseArePokeBalls
	closemessage
	end

OaksLab_EventScript_OaksLastPokemon:
	msgbox OaksLab_Text_OaksLastPokemon
	closemessage
	end

OaksLab_EventScript_PlayerInspectsBulbasaursBall::
	showmonpic SPECIES_BULBASAUR, 10, 3
	playmoncry SPECIES_BULBASAUR, 0
	msgbox OaksLab_Text_IsBulbasaurYourChoice, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq OaksLab_EventScript_End
	closemessage
	removeobject 8
	setflag FLAG_HIDE_BULBASAURS_BALL
	hidemonpic
	msgbox OaksLab_Text_ThisPokemonIsQuiteEnergetic
	closemessage
	playfanfare MUS_RG_FAN5
	bufferspeciesname 0, SPECIES_BULBASAUR
	msgbox OaksLab_Text_ReceivedPokemonFromOak
	waitfanfare
	closemessage
	setvar VAR_STARTER_MON, 0
	givemon SPECIES_BULBASAUR, 5, ITEM_ORAN_BERRY
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_INFLAG2, 3
	msgbox OaksLab_Text_DoYouWantToNicknameYourPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq OaksLab_EventScript_PlayerChoseAPokemon
	closemessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto OaksLab_EventScript_PlayerChoseAPokemon
OaksLab_EventScript_PlayerInspectsCharmandersBall::
	showmonpic SPECIES_CHARMANDER, 10, 3
	playmoncry SPECIES_CHARMANDER, 0
	msgbox OaksLab_Text_IsCharmanderYourChoice, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq OaksLab_EventScript_End
	closemessage
	removeobject 7
	setflag FLAG_HIDE_CHARMANDERS_BALL
	hidemonpic
	msgbox OaksLab_Text_ThisPokemonIsQuiteEnergetic
	closemessage
	playfanfare MUS_RG_FAN5
	bufferspeciesname 0, SPECIES_CHARMANDER
	msgbox OaksLab_Text_ReceivedPokemonFromOak
	waitfanfare
	closemessage
	setvar VAR_STARTER_MON, 1
	givemon SPECIES_CHARMANDER, 5, ITEM_ORAN_BERRY
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_INFLAG2, 3
	msgbox OaksLab_Text_DoYouWantToNicknameYourPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq OaksLab_EventScript_PlayerChoseAPokemon
	closemessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto OaksLab_EventScript_PlayerChoseAPokemon
OaksLab_EventScript_PlayerInspectsSquirtlesBall::
	showmonpic SPECIES_SQUIRTLE, 10, 3
	playmoncry SPECIES_SQUIRTLE, 0
	msgbox OaksLab_Text_IsSquirtleYourChoice, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq OaksLab_EventScript_End
	closemessage
	removeobject 6
	setflag FLAG_HIDE_SQUIRTLES_BALL
	hidemonpic
	msgbox OaksLab_Text_ThisPokemonIsQuiteEnergetic
	closemessage
	playfanfare MUS_RG_FAN5
	bufferspeciesname 0, SPECIES_SQUIRTLE
	msgbox OaksLab_Text_ReceivedPokemonFromOak
	waitfanfare
	closemessage
	setvar VAR_STARTER_MON, 2
	givemon SPECIES_SQUIRTLE, 5, ITEM_ORAN_BERRY
	setflag FLAG_SYS_POKEMON_GET
	setvar VAR_INFLAG2, 3
	msgbox OaksLab_Text_DoYouWantToNicknameYourPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq OaksLab_EventScript_PlayerChoseAPokemon
	closemessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto OaksLab_EventScript_PlayerChoseAPokemon

OaksLab_EventScript_End:
	hidemonpic
	closemessage
	end

OaksLab_EventScript_PlayerChoseAPokemon:
	closemessage
	switch VAR_STARTER_MON
	case 0, OaksLab_EventScript_RivalWalksTowardsCharmandersPokeBall
	case 1, OaksLab_EventScript_RivalWalksTowardsSquirtlesPokeBall
	case 2, OaksLab_EventScript_RivalWalksTowardsBulbasaurPokeBall

OaksLab_EventScript_RivalWalksTowardsCharmandersPokeBall:
	applymovement 4, OaksLab_Movement_RivalWalksTowardsCharmandersPokeBall
	waitmovement 0
	msgbox OaksLab_Text_RivalChoseAPokemon
	closemessage
	removeobject 7
	setflag FLAG_HIDE_CHARMANDERS_BALL
	playfanfare MUS_RG_FAN5
	bufferspeciesname 1, SPECIES_CHARMANDER
	msgbox OaksLab_Text_RivalReceivedPokemon
	waitfanfare
	closemessage
	end
OaksLab_EventScript_RivalWalksTowardsSquirtlesPokeBall:
	applymovement 4, OaksLab_Movement_RivalWalksTowardsSquirtlesPokeBall
	waitmovement 0
	msgbox OaksLab_Text_RivalChoseAPokemon
	closemessage
	removeobject 6
	setflag FLAG_HIDE_SQUIRTLES_BALL
	playfanfare MUS_RG_FAN5
	bufferspeciesname 1, SPECIES_SQUIRTLE
	msgbox OaksLab_Text_RivalReceivedPokemon
	waitfanfare
	closemessage
	end
OaksLab_EventScript_RivalWalksTowardsBulbasaurPokeBall:
	applymovement 4, OaksLab_Movement_RivalWalksTowardsBulbasaursPokeBall
	waitmovement 0
	msgbox OaksLab_Text_RivalChoseAPokemon
	closemessage
	removeobject 8
	setflag FLAG_HIDE_BULBASAURS_BALL
	playfanfare MUS_RG_FAN5
	bufferspeciesname 1, SPECIES_BULBASAUR
	msgbox OaksLab_Text_RivalReceivedPokemon
	waitfanfare
	closemessage
	end

OaksLab_EventScript_RivalsPokemonLooksTougherThanThePlayers:
	msgbox OaksLab_Text_RivalsPokemonLooksTougherThanThePlayers, MSGBOX_NPC
	end

OaksLab_EventScript_NotReady::
	compare VAR_INFLAG2, 3
	goto_if_eq OaksLab_EventScript_FirstRivalBattle
	msgbox OaksLab_Text_DontGoYet
	closemessage
	applymovement 255, Common_Movement_WalkUp
	waitmovement 0
	end

OaksLab_EventScript_FirstRivalBattle::
@	TODO: Conversation between the Rival and the Player, and first battle against the rival
	setvar VAR_INFLAG2, 4
	end

OaksLab_Movement_Oak:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	face_down
	step_end

OaksLab_Movement_Player:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

OaksLab_Movement_RivalFaceUp:
	face_up
	step_end

OaksLab_Movement_RivalWalksTowardsCharmandersPokeBall:
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

OaksLab_Movement_RivalWalksTowardsSquirtlesPokeBall:
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

OaksLab_Movement_RivalWalksTowardsBulbasaursPokeBall:
	walk_right
	walk_right
	walk_right
	face_up
	step_end

OaksLab_Movement_RivalWalkFastInPlace:
	walk_in_place_up
	walk_in_place_up
	step_end

OaksLab_Text_GenericAides:
	.string "I study POKéMON as Prof. Oak's\n"
	.string "aide.$"

OaksLab_Text_DifferentAide:
	.string "Prof. Oak may not look like much,\n"
	.string "but he's the authority on POKéMON.\p"
	.string "Many POKéMON TRAINERS hold him in\n"
	.string "high regard.$"

OaksLab_Text_RivalStandingStill:
	.string "Green: What, it's only {PLAYER}?\n"
	.string "Gramps isn't around.$"

OaksLab_Text_RivalIsImpatient:
	.string "Green: Gramps!\n"
	.string "I'm fed up with waiting!$"

OaksLab_Text_OakIsPreparing:
	.string "Oak: Green?\n"
	.string "Let me think…\p"
	.string "Oh, that's right, I told you to\n"
	.string "come! Just wait!\p"
	.string "Here, {PLAYER}.\p"
	.string "There are three POKéMON here.\p"
	.string "Haha!\p"
	.string "The POKéMON are held inside\n"
	.string "these POKé BALLS.\p"
	.string "When I was young, I was a serious\n"
	.string "POKéMON TRAINER.\p"
	.string "But now, in my old age, I have\n"
	.string "only these three left.\p"
	.string "You can have one.\n"
	.string "Go on, choose!$"

OaksLab_Text_RivalIsVeryImpatient:
	.string "Green: Hey! Gramps! No fair!\n"
	.string "What about me?$"

OaksLab_Text_OakIsClam:
	.string "Oak: Be patient, Green.\n"
	.string "You can have one, too!$"

OaksLab_Text_TheseArePokeBalls:
	.string "Those are POKé BALLS.\n"
	.string "They contain POKéMON!$"

OaksLab_Text_OaksLastPokemon:
	.string "That's Prof. Oak's last POKéMON.$"

OaksLab_Text_DontGoYet:
	.string "Oak: Hey!\n"
	.string "Don't go away yet!$"

OaksLab_Text_RivalCallsYouGreedy:
	.string "Green: Heh, I don't need to be\n"
	.string "greedy like you. I'm mature!\p"
	.string "Go ahead and choose, {PLAYER}!$"

OaksLab_Text_OakTellsYouToChoose:
	.string "Oak: Now, {PLAYER}.\p"
	.string "Inside those three POKé BALLS are\n"
	.string "POKéMON.\p"
	.string "Which one will you choose for\n"
	.string "yourself?$"

OaksLab_Text_OakInformsYou:
	.string "Oak: If a wild POKéMON appears,\n"
	.string "your POKéMON can battle it.\p"
	.string "With it at your side, you should be\n"
	.string "able to reach the next town.$"

OaksLab_Text_OakSuggestsYouToBattleALot:
	.string "Oak: {PLAYER}, raise your young\n"
	.string "POKéMON by making it battle.\p"
	.string "It has to battle for it to grow.$"

OaksLab_Text_Test:
	.string "So far so good.$"

OaksLab_Text_IsBulbasaurYourChoice:
	.string "I see! BULBASAUR is your choice.\n"
	.string "It's very easy to raise.\p"
	.string "So, {PLAYER}, you want to go with\n"
	.string "the GRASS POKéMON BULBASAUR?$"

OaksLab_Text_IsCharmanderYourChoice:
	.string "Ah! CHARMANDER is your choice.\n"
	.string "You should raise it patiently.\p"
	.string "So, {PLAYER}, you're claiming the\n"
	.string "FIRE POKéMON CHARMANDER?$"

OaksLab_Text_IsSquirtleYourChoice:
	.string "Hm! SQUIRTLE is your choice.\n"
	.string "It's one worth raising.\p"
	.string "So, {PLAYER}, you've decided on the\n"
	.string "WATER POKéMON SQUIRTLE?$"

OaksLab_Text_ThisPokemonIsQuiteEnergetic:
	.string "This POKéMON is really quite\n"
	.string "energetic!$"

OaksLab_Text_ReceivedPokemonFromOak:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from Prof. Oak!$"

OaksLab_Text_DoYouWantToNicknameYourPokemon:
	.string "Do you want to give a nickname to\n"
	.string "this {STR_VAR_1}?$"

OaksLab_Text_RivalChoseAPokemon:
	.string "Green: I'll take this one, then!$"

OaksLab_Text_RivalReceivedPokemon:
	.string "Green received the {STR_VAR_2}\n"
	.string "from Prof. Oak!$"

OaksLab_Text_RivalsPokemonLooksTougherThanThePlayers:
	.string "Green: My POKéMON looks a lot\n"
	.string "tougher than yours.$"
