.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4

PetalburgWoods_MapScripts:: @ 822DFD6
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft:: @ 822DFD7
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight:: @ 822E079
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro:: @ 822E124
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle:: @ 822E138
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull:: @ 822E17D
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish:: @ 822E18B
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher:: @ 822E1A7
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround: @ 822E1B1
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft: @ 822E1C2
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft: @ 822E1CB
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight: @ 822E1D0
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight: @ 822E1D7
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave: @ 822E1E0
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft: @ 822E1E4
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_fastest_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight: @ 822E1EA
	walk_fast_down
	walk_fast_right
	walk_in_place_fastest_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit: @ 822E1EE
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft: @ 822E1F6
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff: @ 822E1F9
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway: @ 822E1FD
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight: @ 822E205
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance: @ 822E209
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer: @ 822E20E
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1:: @ 822E210
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2:: @ 822E219
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl:: @ 822E222
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed:: @ 822E251
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1:: @ 822E25B
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2:: @ 822E264
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle:: @ 822E26D
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James:: @ 822E284
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames:: @ 822E2C5
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames:: @ 822E2D6
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2:: @ 822E2EF
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2:: @ 822E302
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch:: @ 822E31B
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound: @ 822E332
	.string "Hmmm…\n"
	.string "Not a one to be found…$"

PetalburgWoods_Text_HaveYouSeenShroomish: @ 822E34F
	.string "Hello, have you seen any Pokémon\n"
	.string "called Dartrix around here?\p"
	.string "I really love that Pokémon.$"

PetalburgWoods_Text_IWasGoingToAmbushYou: @ 822E3AA
	.string "I was going to ambush you, but you\n"
	.string "had to dawdle in Petalburg Woods\l"
	.string "forever, didn't you?\p"
	.string "I got sick of waiting, so here I am!$"

PetalburgWoods_Text_HandOverThosePapers: @ 822E428
	.string "You! Devon Researcher!\p"
	.string "Hand over those papers!$"

PetalburgWoods_Text_YouHaveToHelpMe: @ 822E457
	.string "Aiyeeeh!\p"
	.string "You're a Pokémon TRAINER, aren't you?\n"
	.string "You've got to help me, please!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua: @ 822E4A5
	.string "Hunh? What do you think you're doing?\n"
	.string "What, you're going to protect him?\p"
	.string "No one who crosses Team Obsidian\n"
	.string "gets any mercy, not even you kid!\p"
	.string "Come on and battle me!$"

PetalburgWoods_Text_YoureKiddingMe: @ 822E542
	.string "You're kidding me! I lost to another\n"
	.string "kid!$"

PetalburgWoods_Text_YouveGotSomeNerve: @ 822E563
	.string "Grrr… You've got some nerve\n"
	.string "meddling with Team Obsidian!\l"
	.string "Next time I would use my Pokémon from\p"
	.string "when I was with Team Plasma, but I\n"
	.string "don't have those anymore…\p"
	.string "And, hey, we of Team Obsidian are also\n"
	.string "after something that help us take over.\p"
	.string "I'll let you go today!$"

PetalburgWoods_Text_ThatWasAwfullyClose: @ 822E63D
	.string "Whew…\n"
	.string "That was awfully close!\p"
	.string "Thanks to you, he didn't rob me of\n"
	.string "these important papers.\p"
	.string "I know, I'll give you a Great Ball as\n"
	.string "my thanks!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro: @ 822E6C7
	.string "Didn't that Team Obsidian thug say\n"
	.string "they were after something very\l"
	.string "important, too?$"

PetalburgWoods_Text_ICantBeWastingTime: @ 822E712
	.string "Uh-oh! It's a crisis!\n"
	.string "I can't be wasting time!$"

PetalburgWoods_Text_YoureLoadedWithItems: @ 822E741
	.string "You're loaded with items.\n"
	.string "I can't give you this Great Ball.$"

PetalburgWoods_Text_GoBugPokemonTeam: @ 822E77D
	.string "I caught a whole bunch of Pokémon!\p"
	.string "Go, go, go!\n"
	.string "My Bug Pokémon team!$"

PetalburgWoods_Text_ICouldntWin: @ 822E7C1
	.string "I have all these Pokémon,\n"
	.string "but I couldn't win…$"

PetalburgWoods_Text_ImOutOfPokeBalls: @ 822E7EF
	.string "I caught a bunch of Pokémon.\n"
	.string "Now I'm out of Poké Balls.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon: @ 822E827
	.string "If you take Bug Pokémon to school,\n"
	.string "you get to be instantly popular!$"

PetalburgWoods_Text_CantBePopularIfILose: @ 822E86B
	.string "I can't be popular if I lose.$"

PetalburgWoods_Text_PeopleRespectYou: @ 822E889
	.string "If you have a big Bug POKéMON,\n"
	.string "people respect you for it.$"

PetalburgWoods_Text_IWantRematch1: @ 822E8C3
	.string "I want a rematch when my Bug\n"
	.string "Pokémon grow up!\p"
	.string "I'm registering you in my Pokénav!$"

PetalburgWoods_Text_IWantRematch2: @ 822E914
	.string "I want a rematch when my Bug \n"
	.string "Pokémon grow up!\p"
	.string "I'm registering you in my POKéNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown: @ 822E966
	.string "My Bug Pokémon have grown.\n"
	.string "I'll be popular again.$"

PetalburgWoods_Text_CantBePopularIfLose: @ 822E998
	.string "I can't be popular if I lose.$"

PetalburgWoods_Text_IveBeenTrainingHard: @ 822E9B6
	.string "You get to be popular if you have\n"
	.string "strong Pokémon, right?\l"
	.string "So, I've been training hard.$"

PetalburgWoods_Text_StayOutOfTallGrass: @ 822EA0C
	.string "Yo, there!\n"
	.string "Your Pokémon doing okay?\p"
	.string "If your Pokémon are weak and you want\n"
	.string "to avoid battles, you should stay out\l"
	.string "of tall grass.$"

PetalburgWoods_Text_HiddenItemsExplanation: @ 822EA8B
	.string "Sometimes, there are things on the\n"
	.string "ground even if you can't see them.\p"
	.string "That's why I always check where I'm\n"
	.string "walking.$"

PetalburgWoods_Text_TryUsingThisItem: @ 822EAFE
	.string "Oh, neat!\n"
	.string "That's the BADGE from RUSTBORO GYM!\p"
	.string "You must be a TRAINER.\n"
	.string "You should try using this item.$"

PetalburgWoods_Text_MiracleSeedExplanation: @ 822EB63
	.string "It's a MIRACLE SEED.\n"
	.string "If a Pokémon holds that item, its\l"
	.string "GRASS-type moves become stronger.\p"
	.string "Besides MIRACLE SEED, I think there are\n"
	.string "other convenient items for Pokémon\l"
	.string "to hold.$"

PetalburgWoods_Text_TrainerTipsExperience: @ 822EC10
	.string "TRAINER TIPS\p"
	.string "Any Pokémon that appears even once\n"
	.string "in a battle is awarded EXP Points.\p"
	.string "To raise a weak Pokémon, put it at the\n"
	.string "left of the team list.\p"
	.string "As soon as a battle starts, switch it\n"
	.string "out. It will earn EXP Points without\l"
	.string "being exposed to any harm.$"

PetalburgWoods_Text_TrainerTipsPP: @ 822ED07
	.string "TRAINER TIPS\p"
	.string "In addition to Hit Points (HP), Pokémon\n"
	.string "have Power Points (PP) that are used to\l"
	.string "make moves during battle.\p"
	.string "If a Pokémon runs out of PP, it must be\n"
	.string "taken to a Pokémon CENTER.$"

PetalburgWoods_EventScript_Wilburn::
	trainerbattle_single TRAINER_WILBURN, PetalburgWoods_Text_WilburnIntro, PetalburgWoods_Text_WilburnDefeated
	msgbox PetalburgWoods_Text_WilburnPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_Palmer::
	trainerbattle_single TRAINER_PALMER, PetalburgWoods_Text_PalmerIntro, PetalburgWoods_Text_PalmerDefeated
	msgbox PetalburgWoods_Text_PalmerPostBattle, MSGBOX_AUTOCLOSE
	end
	
PetalburgWoods_EventScript_Mackenzie::
	trainerbattle_single TRAINER_MACKENZIE, PetalburgWoods_Text_MackenzieIntro, PetalburgWoods_Text_MackenzieDefeated
	msgbox PetalburgWoods_Text_MackenziePostBattle, MSGBOX_AUTOCLOSE
	end
	
PetalburgWoods_EventScript_Sterling::
	trainerbattle_single TRAINER_STERLING, PetalburgWoods_Text_SterlingIntro, PetalburgWoods_Text_SterlingDefeated
	msgbox PetalburgWoods_Text_SterlingPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_Rudolph::
	trainerbattle_single TRAINER_RUDOLPH, PetalburgWoods_Text_RudolphIntro, PetalburgWoods_Text_RudolphDefeated
	msgbox PetalburgWoods_Text_RudolphPostBattle, MSGBOX_AUTOCLOSE
	end
	
PetalburgWoods_EventScript_IgnesCheckFlag::
	goto_if_set FLAG_BADGE01_GET, PetalburgWoods_EventScript_IgnesFirstBattle
	release
	end

PetalburgWoods_EventScript_IgnesFirstBattle::
	addobject 15
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setvar VAR_MEET_IGNES, 1
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement 15, Ignes_Moves_Towards_Player
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Face_Ignes
	waitmovement 0
	msgbox PetalburgWoods_Text_IgnesNoticesYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_IGNES_PETALBURGWOODS, PetalburgWoods_Text_NextTime
	msgbox PetalburgWoods_Text_IgnesNextCity, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_EXP_SHARE
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox PetalburgWoods_Text_IgnesFigureItOut, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement 15, Ignes_Heads_To_Antiquity
	waitmovement 0
	removeobject 15
	setflag FLAG_HIDE_PETALBURG_GYM_WALLY
	releaseall
	end

PetalburgWoods_EventScript_IgnesCheckFlag2::
	goto_if_set FLAG_BADGE01_GET, PetalburgWoods_EventScript_IgnesFirstBattle2
	release
	end

PetalburgWoods_EventScript_IgnesFirstBattle2::
	addobject 15
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setvar VAR_MEET_IGNES, 1
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement 15, Ignes_Moves_Towards_Player2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Face_Ignes
	waitmovement 0
	msgbox PetalburgWoods_Text_IgnesNoticesYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_IGNES_PETALBURGWOODS, PetalburgWoods_Text_NextTime
	msgbox PetalburgWoods_Text_IgnesNextCity, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_EXP_SHARE
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox PetalburgWoods_Text_IgnesFigureItOut, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	applymovement 15, Ignes_Heads_To_Antiquity2
	waitmovement 0
	removeobject 15
	setflag FLAG_HIDE_PETALBURG_GYM_WALLY
	releaseall
	end

Ignes_Moves_Towards_Player:
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

Ignes_Heads_To_Antiquity:
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

Ignes_Moves_Towards_Player2:
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_up
	walk_right
	step_end

Ignes_Heads_To_Antiquity2:
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

Face_Ignes:
	face_left
	step_end
	
PetalburgWoods_Text_WilburnIntro:
	.string "I heard this forest was good for camping.\p"
	.string "Let's see if the same goes for battling.$"

PetalburgWoods_Text_WilburnDefeated:
	.string "Can't believe I lost!$"

PetalburgWoods_Text_WilburnPostBattle:
	.string "Maybe I should go somewhere else.$"

PetalburgWoods_Text_PalmerIntro:
	.string "Nobody catches bug better than me!$"

PetalburgWoods_Text_PalmerDefeated:
	.string "Where are your bugs man!?$"

PetalburgWoods_Text_PalmerPostBattle:
	.string "Even if I lost, I'm still the best\n"
	.string "bug catcher around.$"

PetalburgWoods_Text_MackenzieIntro:
	.string "Let's battle while I wait for someone.$"

PetalburgWoods_Text_MackenzieDefeated:
	.string "That went by too fast.$"

PetalburgWoods_Text_MackenziePostBattle:
	.string "He's taking longer than i thought.$"

PetalburgWoods_Text_SterlingIntro:
	.string "I caught these rare bugs in the\n"
	.string "Bug Catching Contest in Johto.$"

PetalburgWoods_Text_SterlingDefeated:
	.string "I guess even if they're rare they\n"
	.string "not strong.$"

PetalburgWoods_Text_SterlingPostBattle:
	.string "I'm gonna go back one day and get\n"
	.string "some strong bugs.$"

PetalburgWoods_Text_RudolphIntro:
	.string "Time for a big Reel!$"
	
PetalburgWoods_Text_RudolphDefeated:
	.string "I took the bait huh.$"

PetalburgWoods_Text_RudolphPostBattle:
	.string "I need a better fishing rod.$"

PetalburgWoods_Text_IgnesNoticesYou:
	.string "Ignes:Ohh look who it is.\n"
	.string "I noticed you beat the first gym so,\l"
	.string "I was catching up to you to battle\p"
	.string "you properly this time.\p"
	.string "LET'S GO!!!$"

PetalburgWoods_Text_NextTime:
	.string "Next Time I'll win.$"

PetalburgWoods_Text_IgnesNextCity:
	.string "I'm headed to Antiquity since\n"
	.string "I heard there's a way to Dewford\l"
	.string "somewhere in the city.\p"
	.string "If you want to make any progress I\n"
	.string "suggest you do the same thing.\p"
	.string "I also ran into {RIVAL} earlier and\n"
	.string "they wanted me to give you this.$"
	
PetalburgWoods_Text_IgnesFigureItOut:
	.string "Ignes: You're smart.\n"
	.string "You can figure out how it works\l"
	.string "yourself.\p"
	.string "I'm going ahead because I'm just.\n"
	.string "Built uniquely.$"