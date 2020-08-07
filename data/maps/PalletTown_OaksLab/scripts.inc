PalletTown_OaksLab_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, OaksLab_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OaksLab_OnWarp
	.byte 0

OaksLab_OnLoad:
	setobjectxyperm 5, 6, 11
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_UP
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
	goto OaksLab_IntroductionToPokemon

OaksLab_IntroductionToPokemon:
@	TODO: Conversation between Oak and Green before the Player chooses their Pokémon
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

OaksLab_GenericAides::
	msgbox OaksLab_Text_GenericAides, MSGBOX_NPC
	end

OaksLab_DifferentAide::
	msgbox OaksLab_Text_DifferentAide, MSGBOX_NPC
	end

OaksLab_RivalStandingStill::
	msgbox OaksLab_Text_RivalStandingStill, MSGBOX_NPC
	end

OaksLab_Text_GenericAides:
	.string "I study POKéMON as PROF. OAK's\n"
	.string "AIDE.$"

OaksLab_Text_DifferentAide:
	.string "PROF. OAK may not look like much,\n"
	.string "but he's the authority on POKéMON.\p"
	.string "Many POKéMON TRAINERS hold him in\n"
	.string "high regard.$"

OaksLab_Text_RivalStandingStill:
	.string "Green: What, it's only {PLAYER}?\n"
	.string "Gramps isn't around.$"

OaksLab_Text_Test:
	.string "Test, test. 123, 123.$"
