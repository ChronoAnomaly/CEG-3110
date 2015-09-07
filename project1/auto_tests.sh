#!/bin/bash

function one_dice {
	echo 'Testing one dice output...'
	for i in {1..5000}; do
		echo '1' | ./worley_dice >> dice_1.log
		sleep .63
	done
}

function two_dice {
	echo 'Testing two dice output...'
	for i in {1..5000}; do
		echo '2' | ./worley_dice >> dice_2.log
		sleep .63
	done
}

function three_dice {
	echo 'Testing three dice output...'
	for i in {1..5000}; do
		echo '3' | ./worley_dice >> dice_3.log
		sleep .63
	done
}

function four_dice {
	echo 'Testing four dice output...'
	for i in {1..5000}; do
		echo '4' | ./worley_dice >> dice_4.log
		sleep .63
	done
}

function five_dice {
	echo 'Testing five dice output...'
	for i in {1..5000}; do
		echo '5' | ./worley_dice >> dice_5.log
		sleep .63
	done
}

function quit {
	echo 'Exiting testing script...'
	exit
}

one_dice
two_dice
three_dice
four_dice
five_dice
quit
