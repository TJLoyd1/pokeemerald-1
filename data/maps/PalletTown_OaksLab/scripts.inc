PalletTown_OaksLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OaksLab_EventScript_Journey
	.byte 0

OaksLab_EventScript_Journey:
	compare VAR_INFLAG2, 1
	goto_if_eq OaksLab_BeginningPreparations
	compare VAR_INFLAG2, 3
	goto_if_gt OaksLab_AdventureStarted
	end

OaksLab_BeginningPreparations:
	removeobject 6, MAP_PALLET_TOWN_OAKS_LAB
	goto OaksLab_Beginning
OaksLab_Beginning:
	applymovement 5, OakToPlace
	waitmovement 0
	delay 40
	applymovement 255, PlayerToPlace
	waitmovement 0
	applymovement 4, RivalToOak
	waitmovement 0
	applymovement 4, RivalImpacient
	waitmovement 0
	delay 40
	msgbox OaksLab_Text_RivalComplaints, MSGBOX_DEFAULT
	msgbox OaksLab_Text_OakAnswers, MSGBOX_DEFAULT
	msgbox OaksLab_Text_RivalComplaintsAgain, MSGBOX_DEFAULT
	setvar VAR_INFLAG2, 2
	end

OaksLab_Oak::
	checkflag FLAG_ADVENTURE_STARTED
	vgoto_if 1, PlayersTask
	compare VAR_RIVAL_STARTER_MON, 0
	goto_if_gt OaksLab_BeginnerTip
	compare VAR_INFLAG2, 2
	goto_if_eq PickOne
	end
PickOne:
	msgbox OaksLab_Text_PickOne, MSGBOX_NPC
	end
OaksLab_BeginnerTip:
	msgbox OaksLab_Text_BeginnerTip, MSGBOX_NPC
	end
PlayersTask:
	msgbox OaksLab_Text_PlayersTask, MSGBOX_NPC
	end

OaksLab_Rival::
	compare VAR_INFLAG2, 2
	goto_if_eq GoAhead
	compare VAR_STARTER_MON, 0
	goto_if_gt OaksLab_RivalsMonTougher
	msgbox OaksLab_Text_Rival, MSGBOX_NPC
	end
GoAhead:
	msgbox OaksLab_Text_GoAhead, MSGBOX_NPC
	end
OaksLab_RivalsMonTougher:
	msgbox OaksLab_Text_RivalsMonTougher, MSGBOX_NPC
	end

OaksLab_AdventureStarted:
	lock
	faceplayer
	message OaksLab_Text_Something
	closemessage
	release
	end

PickAStarter_Bulbasaur::
	bufferspeciesname 0, SPECIES_BULBASAUR
	applymovement 6, OakToBalls
	showmonpic SPECIES_BULBASAUR, 10, 3
	msgbox OaksLab_Text_BulbasaurBall, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PickAStarter_ChoseBulbasaur
	end
PickAStarter_Charmander::
	bufferspeciesname 0, SPECIES_CHARMANDER
	applymovement 6, OakToBalls
	showmonpic SPECIES_CHARMANDER, 10, 3
	msgbox OaksLab_Text_CharmanderBall, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PickAStarter_ChoseCharmander
	end
PickAStarter_Squirtle::
	bufferspeciesname 0, SPECIES_SQUIRTLE
	applymovement 6, OakToBalls
	showmonpic SPECIES_SQUIRTLE, 10, 3
	msgbox OaksLab_Text_SquirtleBall, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PickAStarter_ChoseSquirtle
	end

PickAStarter_ChoseBulbasaur:
	bufferspeciesname 1, SPECIES_BULBASAUR
	setvar VAR_STARTER_MON, 1
	setflag FLAG_SYS_POKEMON_GET
	removeobject 9
	hidemonpic
	msgbox OaksLab_Text_Energetic, MSGBOX_DEFAULT
	msgbox OaksLab_Text_ObtainedMon, MSGBOX_DEFAULT
	msgbox OaksLab_Text_Nickname, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq OaksLab_ReadyToGo1
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	setflag FLAG_CHOSE_BULBASAUR
	goto_if_eq OaksLab_ReadyToGo1
PickAStarter_ChoseCharmander:
	bufferspeciesname 1, SPECIES_CHARMANDER
	setvar VAR_STARTER_MON, 2
	setflag FLAG_SYS_POKEMON_GET
	removeobject 8
	hidemonpic
	msgbox OaksLab_Text_Energetic, MSGBOX_DEFAULT
	msgbox OaksLab_Text_ObtainedMon, MSGBOX_DEFAULT
	msgbox OaksLab_Text_Nickname, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq OaksLab_ReadyToGo2
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	setflag FLAG_CHOSE_CHARMANDER
	goto_if_eq OaksLab_ReadyToGo2
PickAStarter_ChoseSquirtle:
	bufferspeciesname 1, SPECIES_SQUIRTLE
	setvar VAR_STARTER_MON, 3
	setflag FLAG_SYS_POKEMON_GET
	removeobject 7
	hidemonpic
	msgbox OaksLab_Text_Energetic, MSGBOX_DEFAULT
	msgbox OaksLab_Text_ObtainedMon, MSGBOX_DEFAULT
	msgbox OaksLab_Text_Nickname, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq OaksLab_ReadyToGo3
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	setflag FLAG_CHOSE_SQUIRTLE
	goto_if_eq OaksLab_ReadyToGo3

OaksLab_ReadyToGo1:
	applymovement 4, RivalToCharmander
	waitmovement 0
	msgbox OaksLab_Text_RivalsChoice, MSGBOX_DEFAULT
	msgbox OaksLab_Text_RivalReceivedStarter, MSGBOX_DEFAULT
	setvar VAR_RIVAL_STARTER_MON, 1
	end
OaksLab_ReadyToGo2:
	applymovement 4, RivalToSquirtle
	waitmovement 0
	msgbox OaksLab_Text_RivalsChoice, MSGBOX_DEFAULT
	msgbox OaksLab_Text_RivalReceivedStarter, MSGBOX_DEFAULT
	setvar VAR_RIVAL_STARTER_MON, 2
	end
OaksLab_ReadyToGo3:
	applymovement 4, RivalToBulbasaur
	waitmovement 0
	msgbox OaksLab_Text_RivalsChoice, MSGBOX_DEFAULT
	msgbox OaksLab_Text_RivalReceivedStarter, MSGBOX_DEFAULT
	setvar VAR_RIVAL_STARTER_MON, 3
	end

OaksLab_InvisibleBarrier::
	compare VAR_RIVAL_STARTER_MON, 0
	goto_if_eq OaksLab_DidntChoose
	applymovement 4, RivalLooksPlayer
	applymovement 255, PlayerLooksRival
	waitmovement 0
	compare VAR_RIVAL_STARTER_MON, 1
	goto_if_eq FirstRivalBattle1
	compare VAR_RIVAL_STARTER_MON, 2
	goto_if_eq FirstRivalBattle2
	compare VAR_RIVAL_STARTER_MON, 3
	goto_if_eq FirstRivalBattle3
	end
OaksLab_DidntChoose:
	msgbox OaksLab_Text_DontLeave, MSGBOX_NPC
	end

FirstRivalBattle1:
	msgbox OaksLab_Text_RivalApproaching, MSGBOX_DEFAULT
	applymovement 4, RivalToPlayer1
	waitmovement 0
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_WALLY_VR_1, 0, OaksLab_RivalBattleIntroText, OaksLab_RivalBattleVictoryText, OaksLab_RivalBattle_MovingOn
FirstRivalBattle2:
	applymovement 4, RivalToPlayer2
	waitmovement 0
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_WALLY_VR_2, 0, OaksLab_RivalBattleIntroText, OaksLab_RivalBattleVictoryText, OaksLab_RivalBattle_MovingOn
FirstRivalBattle3:
	applymovement 4, RivalToPlayer3
	waitmovement 0
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_WALLY_VR_3, 0, OaksLab_RivalBattleIntroText, OaksLab_RivalBattleVictoryText, OaksLab_RivalBattle_MovingOn

OaksLab_RivalBattle_MovingOn:
	msgbox OaksLab_RivalBattleFinished, MSGBOX_DEFAULT
	applymovement 4, RivalLeavesTheLab
	waitmovement 0
	removeobject 4
	setflag FLAG_HIDE_OAK_PALLET_TOWN
	setflag FLAG_HIDE_RIVAL_OAKS_LAB
	setflag FLAG_ADVENTURE_STARTED
	end

OaksLab_GenericAides::
	msgbox OaksLab_Text_GenericAides, MSGBOX_NPC
	end

OaksLab_DifferentAide::
	msgbox OaksLab_Text_DifferentAide, MSGBOX_NPC
	end

OaksLab_Text_GenericAides:
	.string "I study POKéMON as PROF. OAK's\n"
	.string "AIDE.$"

OaksLab_Text_DifferentAide:
	.string "PROF. OAK may not look like much,\n"
	.string "but he's the authority on POKéMON.\p"
	.string "Many POKéMON TRAINERS hold him in\n"
	.string "high regard.$"

OaksLab_Text_RivalComplaints:
	.string "{RIVAL}: Gramps!\n"
	.string "I'm fed up with waiting!$"

OaksLab_Text_OakAnswers:
	.string "OAK: {RIVAL}?\n"
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

OaksLab_Text_RivalComplaintsAgain:
	.string "{RIVAL}: Hey! Gramps! No fair!\n"
	.string "What about me?\p"
	.string "Oak: Be patient, {RIVAL}.\n"
	.string "You can have one, too!$"

OaksLab_Text_PickOne:
	.string "OAK: Now, {PLAYER}.\p"
	.string "Inside those three POKé BALLS are\n"
	.string "POKéMON.\p"
	.string "Which one will you choose for\n"
	.string "yourself?$"

OaksLab_Text_BeginnerTip:
	.string "OAK: If a wild POKéMON appears,\n"
	.string "your POKéMON can battle it.\p"
	.string "With it at your side, you should be\n"
	.string "able to reach the next town.$"

OaksLab_Text_PlayersTask:
	.string "OAK: {PLAYER}, raise your young\n"
	.string "POKéMON by making it battle.\p"
	.string "It has to battle for it to grow.$"

OaksLab_Text_Rival:
	.string "{RIVAL}: What, it's only {PLAYER}?\n"
	.string "Gramps isn't around.$"

OaksLab_Text_GoAhead:
	.string "{RIVAL}: Heh, I don't need to be\n"
	.string "greedy like you. I'm mature!\p"
	.string "Go ahead and choose, {PLAYER}!$"

OaksLab_Text_RivalsMonTougher:
	.string "{RIVAL}: My POKéMON looks a lot\n"
	.string "tougher than yours.$"

OaksLab_Text_BulbasaurBall:
	.string "I see! {STR_VAR_1} is your choice.\n"
	.string "It's very easy to raise.\p"
	.string "So, {PLAYER}, do you want to go with\n"
	.string "the GRASS POKéMON {STR_VAR_1}?$"

OaksLab_Text_CharmanderBall:
	.string "Ah! {STR_VAR_1} is your choice.\n"
	.string "You should raise it patiently.\p"
	.string "So, {PLAYER}, do you want to go with\n"
	.string "the FIRE POKéMON {STR_VAR_1}?$"

OaksLab_Text_SquirtleBall:
	.string "Hm! {STR_VAR_1} is your choice.\n"
	.string "It's one worth raising.\p"
	.string "So, {PLAYER}, do you want to go with\n"
	.string "the WATER POKéMON {STR_VAR_1}?$"

OaksLab_Text_Energetic:
	.string "This POKéMON is really quite\n"
	.string "energetic!$"

OaksLab_Text_ObtainedMon:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. OAK!$"

OaksLab_Text_Nickname:
	.string "Do you want to give a nickname to\n"
	.string "this {STR_VAR_1}?$"

OaksLab_Text_RivalsChoice:
	.string "{RIVAL}: I'll take this one, then!$"

OaksLab_Text_RivalReceivedStarter:
	.string "{RIVAL} received the {STR_VAR_2}\n"
	.string "from PROF. OAK!$"

OaksLab_Text_DontLeave:
	.string "OAK: Hey!\n"
	.string "Don't go away yet!$"

OaksLab_Text_RivalApproaching:
	.string "{RIVAL}: Wait, {PLAYER}!\n"
	.string "Let's check out our POKéMON!$"

OaksLab_RivalBattleIntroText:
	.string "Come on, I'll take you on!$"

OaksLab_RivalBattleVictoryText:
	.string "WHAT?\n"
	.string "Unbelievable!\l"
	.string "I picked the wrong POKéMON!$"

OaksLab_RivalBattleFinished:
	.string "{RIVAL}: Okay! I'll make my\n"
	.string "POKéMON battle to toughen it up!\p"
	.string "{PLAYER}! Gramps!\n"
	.string "Smell you later!$"

OaksLab_Text_Something:
	.string "Idr what to put here LOL.$"

OakToPlace:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	face_down
	step_end

PlayerToPlace:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

RivalToOak:
	face_up
	step_end

RivalImpacient:
	walk_in_place_fast_up
	step_end

OakToBalls:
	face_right
	step_end

RivalToCharmander:
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_up
	step_end
RivalToSquirtle:
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	step_end
RivalToBulbasaur:
	walk_right
	walk_right
	walk_right
	face_up
	step_end

RivalLooksPlayer:
	face_down
	step_end
PlayerLooksRival:
	face_up
	step_end

RivalToPlayer1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end
RivalToPlayer2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end	
RivalToPlayer3:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RivalLeavesTheLab:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
