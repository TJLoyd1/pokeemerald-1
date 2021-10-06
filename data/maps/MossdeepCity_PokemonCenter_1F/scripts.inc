.set LOCALID_NURSE, 1

MossdeepCity_PokemonCenter_1F_MapScripts:: @ 822223F
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MossdeepCity_PokemonCenter_1F_OnTransition: @ 822224A
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

MossdeepCity_PokemonCenter_1F_EventScript_Nurse:: @ 822224E
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_Woman:: @ 822225C
	msgbox MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_EventScript_Girl:: @ 8222265
	msgbox MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable: @ 822226E
	.string "The GYM LEADERS in this town are\n"
	.string "a formidable duo.\p"
	.string "Their combination attacks are, like,\n"
	.string "excellent and wow!$"

MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves: @ 82222D9
	.string "Depending on the special abilities of\n"
	.string "POKéMON, some moves might change\l"
	.string "or not work at all.$"

PokemonCenter_1F_EventScript_EvIvShower::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, PokemonCenter_1F_EventScript_AskShowEvsIvs
	msgbox PokemonCenter_1F_Text_ImTheEvIvShower, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto PokemonCenter_1F_EventScript_AskShowEvsIvs
	end

PokemonCenter_1F_EventScript_AskShowEvsIvs::
	msgbox PokemonCenter_1F_Text_WantMeToShowEvsIvs, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, PokemonCenter_1F_EventScript_ComeBackAnotherTime
	special ShowEvIvScreen
	goto PokemonCenter_1F_EventScript_ComeBackAnotherTime
	end

PokemonCenter_1F_EventScript_ComeBackAnotherTime:: @ 8201452
	msgbox PokemonCenter_1F_Text_ComeBackAnotherTime, MSGBOX_DEFAULT
	releaseall
	end

PokemonCenter_1F_Text_ImTheEvIvShower: @ 820145C
	.string "I'm the Evs/Ivs Guy.\p"
	.string "I can tell all of Evs and Ivs that\n"
	.string	"your Pokémon has.\p"
	.string "I can show you what that Pokémon\n"
	.string "of yours Evs and Ivs are if you'd\l"
	.string "like.\p"

PokemonCenter_1F_Text_WantMeToShowEvsIvs:
	.string "Do you want me to show you your\n"
	.string	"Pokémon's Evs and Ivs?$"

PokemonCenter_1F_Text_ComeBackAnotherTime:
	.string "Come back another time.$"
	