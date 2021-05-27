.set LOCALID_NURSE, 1

OldaleTown_PokemonCenter_1F_MapScripts:: @ 81FC006
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition: @ 81FC011
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse:: @ 81FC01A
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman:: @ 81FC028
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy:: @ 81FC031
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl:: @ 81FC03A
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable:: @ 81FC04F
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC: @ 81FC059
	.string "That PC in the corner there is\n"
	.string "for any Pokémon Trainer to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat: @ 81FC0CD
	.string "Pokémon Centers are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable: @ 81FC148
	.string "The Pokémon Wireless Club on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub: @ 81FC1B9
	.string "The Pokémon Wireless Club on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"

OldaleTown_PokemonCenter_1F_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, OldaleTown_PokemonCenter_1F_EventScript_AskTeachMove
	msgbox OldaleTown_PokemonCenter_1F_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto OldaleTown_PokemonCenter_1F_EventScript_AskTeachMove
	end

OldaleTown_PokemonCenter_1F_EventScript_AskTeachMove::
	msgbox OldaleTown_PokemonCenter_1F_Text_WantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, OldaleTown_PokemonCenter_1F_EventScript_ComeBackAnotherTime
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	end

OldaleTown_PokemonCenter_1F_EventScript_ChooseMon:: @ 82013D6
	msgbox OldaleTown_PokemonCenter_1F_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq OldaleTown_PokemonCenter_1F_EventScript_ComeBackAnotherTime
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_1F_EventScript_CantTeachEgg
	compare VAR_0x8005, 0
	goto_if_eq OldaleTown_PokemonCenter_1F_EventScript_NoMoveToTeachMon
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMove
	end

OldaleTown_PokemonCenter_1F_EventScript_ChooseMove:: @ 820140C
	msgbox OldaleTown_PokemonCenter_1F_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	goto OldaleTown_PokemonCenter_1F_EventScript_ComeBackAnotherTime
	end

OldaleTown_PokemonCenter_1F_EventScript_NoMoveToTeachMon:: @ 8201436
	msgbox OldaleTown_PokemonCenter_1F_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	end

OldaleTown_PokemonCenter_1F_EventScript_CantTeachEgg:: @ 8201444
	msgbox OldaleTown_PokemonCenter_1F_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto OldaleTown_PokemonCenter_1F_EventScript_ChooseMon
	end

OldaleTown_PokemonCenter_1F_EventScript_ComeBackAnotherTime:: @ 8201452
	msgbox OldaleTown_PokemonCenter_1F_Text_ComeBackAnotherTime, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_PokemonCenter_1F_Text_ImTheMoveTutor: @ 820145C
	.string "I'm the MOVE TUTOR.\p"
	.string "I know all the moves that POKéMON\n"
	.string "learn--every one of them--and I can\l"
	.string "teach POKéMON those moves.\p"
	.string "I can teach a move to a POKéMON\n"
	.string "of yours if you'd like.\p"

OldaleTown_PokemonCenter_1F_Text_WantMeToTeachMove:
	.string "Do you want me to teach your\n"
	.string	"Pokémon a move.$"
	
OldaleTown_PokemonCenter_1F_Text_TutorWhichMon: @ 82015A5
	.string "Which POKéMON needs tutoring?$"

OldaleTown_PokemonCenter_1F_Text_TeachWhichMove: @ 82015C3
	.string "Which move should I teach?$"

OldaleTown_PokemonCenter_1F_Text_DontHaveMoveToTeachPokemon: @ 82015DE
	.string "Sorry…\p"
	.string "It doesn't appear as if I have any move\n"
	.string "I can teach that POKéMON.$"

OldaleTown_PokemonCenter_1F_Text_CantTeachEgg: @ 8201697
	.string "Hunh? There isn't a single move that\n"
	.string "I can teach an EGG.$"

OldaleTown_PokemonCenter_1F_Text_ComeBackAnotherTime:
	.string "Come back another time.$"

OldaleTown_PokemonCenter_1F_EventScript_MoveDeleter:: @ 821EA0B
	lockall
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OldaleTown_PokemonCenter_1F_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, OldaleTown_PokemonCenter_1F_EventScript_ChooseMonAndMoveToForget
	case NO, OldaleTown_PokemonCenter_1F_EventScript_ComeAgain
	releaseall
	end

OldaleTown_PokemonCenter_1F_EventScript_ChooseMonAndMoveToForget:: @ 821EA3B
	msgbox OldaleTown_PokemonCenter_1F_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq OldaleTown_PokemonCenter_1F_EventScript_ComeAgain
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_1F_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	compare VAR_RESULT, 1
	goto_if_eq OldaleTown_PokemonCenter_1F_EventScript_MonOnlyKnowsOneMove
	msgbox OldaleTown_PokemonCenter_1F_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	compare VAR_0x8005, MAX_MON_MOVES
	goto_if_eq OldaleTown_PokemonCenter_1F_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox OldaleTown_PokemonCenter_1F_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, OldaleTown_PokemonCenter_1F_EventScript_TryForgetMove
	case NO, OldaleTown_PokemonCenter_1F_EventScript_ComeAgain
	releaseall
	end

OldaleTown_PokemonCenter_1F_EventScript_TryForgetMove:: @ 821EAB0
	special IsLastMonThatKnowsSurf
	compare VAR_RESULT, TRUE
	goto_if_eq OldaleTown_PokemonCenter_1F_EventScript_LastMonWithSurf
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox OldaleTown_PokemonCenter_1F_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_PokemonCenter_1F_EventScript_MonOnlyKnowsOneMove:: @ 821EACF
	special BufferMoveDeleterNicknameAndMove
	msgbox OldaleTown_PokemonCenter_1F_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_PokemonCenter_1F_EventScript_EggCantForgetMoves:: @ 821EADC
	msgbox OldaleTown_PokemonCenter_1F_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_PokemonCenter_1F_EventScript_ComeAgain:: @ 821EAE6
	msgbox OldaleTown_PokemonCenter_1F_Text_ComeAgain, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_PokemonCenter_1F_EventScript_LastMonWithSurf:: @ 821EAF0
	special BufferMoveDeleterNicknameAndMove
	msgbox OldaleTown_PokemonCenter_1F_Text_CantForgetSurf, MSGBOX_DEFAULT
	releaseall
	end

OldaleTown_PokemonCenter_1F_Text_ICanMakeMonForgetMove: @ 821EAFD
	.string "Uh…\n"
	.string "Oh, yes, I'm the MOVE DELETER.\p"
	.string "I can make POKéMON forget their moves.\p"
	.string "Would you like me to do that?$"

OldaleTown_PokemonCenter_1F_Text_WhichMonShouldForget: @ 821EB65
	.string "Which POKéMON should forget a move?$"

OldaleTown_PokemonCenter_1F_Text_WhichMoveShouldBeForgotten: @ 821EB89
	.string "Which move should be forgotten?$"

OldaleTown_PokemonCenter_1F_Text_MonOnlyKnowsOneMove: @ 821EBA9
	.string "{STR_VAR_1} knows only one move\n"
	.string "so it can't be forgotten…$"

OldaleTown_PokemonCenter_1F_Text_MonsMoveShouldBeForgotten: @ 821EBDA
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "That move should be forgotten?$"

OldaleTown_PokemonCenter_1F_Text_MonHasForgottenMove: @ 821EC06
	.string "It worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
	.string "{STR_VAR_2} completely.$"

OldaleTown_PokemonCenter_1F_Text_ComeAgain: @ 821EC3F
	.string "Come again if there are moves that\n"
	.string "need to be forgotten.$"

OldaleTown_PokemonCenter_1F_Text_EggCantForgetMoves: @ 821EC78
	.string "What?\n"
	.string "No EGG should know any moves.$"

OldaleTown_PokemonCenter_1F_Text_CantForgetSurf: @ 821EC9C
	.string "Hm!\p"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
	.string "to forget SURF.$"

OldaleTown_PokemonCenter_1F_EventScript_Man::
	lock
	msgbox OldaleTown_PokemonCenter_1F_Text_MoveRelearnerandDeleter, MSGBOX_NPC
	release
	end

OldaleTown_PokemonCenter_1F_Text_MoveRelearnerandDeleter:
	.string "There's a Move Relearner and Move Deleter\n"
	.string "in every Pokémon Center across the\l"
	.string "region now.$"
	