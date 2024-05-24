/******************************************************************************
Finite State Machine
Project: micro-cli
Description: Simple Command Line Interface for embedded systems

Generated by gv_fsm ruby gem, see https://rubygems.org/gems/gv_fsm
gv_fsm version 0.5.0
Generation date: 2024-04-04 14:35:36 +0200
Generated from: ucli.dot
The finite state machine has:
  5 states
  7 transition functions
Functions and types have been generated with prefix "ucli_"
******************************************************************************/

/**
 * @file ucli-fsm.h
 *
 * @date May 2024
 * @author Enrico Dalla Croce (Kalsifer-742) [kalsifer742@gmail.com]
 */

#ifndef UCLI_FSM_H
#define UCLI_FSM_H

// === Private Includes ===

#include <stdbool.h>

/*** USER CODE BEGIN GLOBALS ***/
/*** USER CODE END GLOBALS ***/

// State data object
// By default set to void; override this typedef or load the proper
// header if you need
/*** USER STATE DATA TYPE BEGIN ***/
typedef void ucli_state_data_t;
/*** USER STATE DATA TYPE END ***/
// Event data object
// By default the struct is empty; put the data of the event inside
// the structure if you need or leave it empty
typedef struct {

    /*** USER CODE BEGIN EVENT_DATA ***/
    char character;
    /*** USER CODE END EVENT_DATA ***/

} ucli_event_data_t;

// NOTHING SHALL BE CHANGED AFTER THIS LINE!

// List of states
typedef enum {
    UCLI_STATE_INIT = 0,
    UCLI_STATE_IDLE,
    UCLI_STATE_DROP,
    UCLI_STATE_PARSE,
    UCLI_STATE_EXEC,
    UCLI_NUM_STATES,
    UCLI_NO_CHANGE
} ucli_state_t;

// State human-readable names
extern const char* ucli_state_names[];

// State function and state transition prototypes
typedef ucli_state_t state_func_t(ucli_state_data_t* data);
typedef void transition_func_t(ucli_state_data_t* data);

// Functions to check and trigger an event
bool ucli_is_event_triggered();
void ucli_event_trigger(ucli_event_data_t* event);

// State functions

// Function to be executed in state init
// valid return states: UCLI_STATE_IDLE
ucli_state_t ucli_do_init(ucli_state_data_t* data);

// Function to be executed in state idle
// valid return states: UCLI_NO_CHANGE, UCLI_STATE_IDLE, UCLI_STATE_DROP,
// UCLI_STATE_PARSE
ucli_state_t ucli_do_idle(ucli_state_data_t* data);

// Function to be executed in state drop
// valid return states: UCLI_NO_CHANGE, UCLI_STATE_IDLE, UCLI_STATE_DROP
ucli_state_t ucli_do_drop(ucli_state_data_t* data);

// Function to be executed in state parse
// valid return states: UCLI_STATE_IDLE, UCLI_STATE_EXEC
ucli_state_t ucli_do_parse(ucli_state_data_t* data);

// Function to be executed in state exec
// valid return states: UCLI_NO_CHANGE, UCLI_STATE_IDLE, UCLI_STATE_EXEC
ucli_state_t ucli_do_exec(ucli_state_data_t* data);

// List of state functions
extern state_func_t* const ucli_state_table[UCLI_NUM_STATES];

// Transition functions
void ucli_init_to_idle(ucli_state_data_t* data);
void ucli_drop(ucli_state_data_t* data);
void ucli_parse(ucli_state_data_t* data);
void ucli_drop_to_idle(ucli_state_data_t* data);
void ucli_parse_to_idle(ucli_state_data_t* data);
void ucli_exec(ucli_state_data_t* data);
void ucli_exec_to_idle(ucli_state_data_t* data);

// Table of transition functions
extern transition_func_t* const ucli_transition_table[UCLI_NUM_STATES]
                                                     [UCLI_NUM_STATES];

// state manager
ucli_state_t ucli_run_state(ucli_state_t cur_state, ucli_state_data_t* data);

#endif
