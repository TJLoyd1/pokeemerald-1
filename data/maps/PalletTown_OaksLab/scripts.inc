PalletTown_OaksLab_MapScripts::
	.byte 0

PalletTown_OaksLab_GenericAides::
	lock
	faceplayer
	msgbox PalletTown_OaksLab_Text_GenericAides, MSGBOX_SIGN
	release
	end

PalletTown_OaksLab_DifferentAide::
	lock
	faceplayer
	msgbox PalletTown_OaksLab_Text_DifferentAide, MSGBOX_SIGN
	release
	end

PalletTown_OaksLab_Rival::
	lock
	faceplayer
	msgbox PalletTown_OaksLab_Text_Rival, MSGBOX_SIGN
	release
	end

PalletTown_OaksLab_Box::
	lock
	faceplayer
	msgbox PalletTown_OaksLab_Text_Box1, MSGBOX_SIGN
	applymovement 4, OaksLab_RivalMovement1
	waitmovement 0
	msgbox PalletTown_OaksLab_Text_Box2, MSGBOX_SIGN
	applymovement 4, OaksLab_RivalMovement2
	waitmovement 0
	release
	end

PalletTown_OaksLab_Text_GenericAides:
	.string "I study POKéMON as PROF. OAK's\n"
	.string "AIDE.$"

PalletTown_OaksLab_Text_DifferentAide:
	.string "PROF. OAK may not look like much,\n"
	.string "but he's the authority on POKéMON.\p"
	.string "Many POKéMON TRAINERS hold him in\n"
	.string "high regard.$"

PalletTown_OaksLab_Text_Rival:
	.string "{RIVAL}: What, it's only {PLAYER}?\n"
	.string "Gramps isn't around.$"

PalletTown_OaksLab_Text_Box1:
	.string "It's a closed box.$"

PalletTown_OaksLab_Text_Box2:
	.string "{RIVAL}: I bet you wanna know what's\n"
	.string "inside. Well, too bad.$"

OaksLab_RivalMovement1:
	face_right
	step_end

OaksLab_RivalMovement2:
	face_down
	step_end
