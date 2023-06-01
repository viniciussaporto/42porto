/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:41:48 by vsa-port          #+#    #+#             */
/*   Updated: 2023/06/01 17:03:51 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MESSAGE_SIZE 1024

// Function to send a single character to the server
void send_char(int pid, char c);

// Function to send a message to the server
void send_message(int pid, char *message);

// Function to send acknowledgment signal to the client
void send_ack(int pid);

// Signal handler function for the server
void sig_handler(int sig, siginfo_t *info, void *context);

#endif
