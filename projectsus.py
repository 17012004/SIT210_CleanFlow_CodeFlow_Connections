def send_command(command, is_high=True):
    try:
        # Create a socket object
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        # Connect to the Arduino
        client_socket.connect((arduino_ip, arduino_port))

        # Send the command (with 'H' for high and 'L' for low)
        if is_high:
            client_socket.send(f"{command}H".encode())
        else:
            client_socket.send(f"{command}L".encode())

        # Close the socket
        client_socket.close()

        status_label.config(text=f"Command sent: {command} {'High' if is_high else 'Low'}")
    except ConnectionRefusedError:
        status_label.config(text="Connection refused. Check Arduino IP and Port.")
    except Exception as e:
        status_label.config(text=f"An error occurred: {e}")

# Function to send high command
def send_high_command(command):
    send_command(command, True)

# Function to send low command
def send_low_command(command):
    send_command(command, False)

# Create buttons for both high and low commands
button_1_high = tk.Button(command_frame, text="Start pumpT1_T2 (High)", command=lambda: send_high_command('1'))
button_1_high.pack()

button_1_low = tk.Button(command_frame, text="Stop pumpT1_T2 (Low)", command=lambda: send_low_command('1'))
button_1_low.pack()

button_2_high = tk.Button(command_frame, text="Start pumpT2_T1 (High)", command=lambda: send_high_command('2'))
button_2_high.pack()

button_2_low = tk.Button(command_frame, text="Stop pumpT2_T1 (Low)", command=lambda: send_low_command('2'))
button_2_low.pack()

button_3_high = tk.Button(command_frame, text="Start pumpT2_T3 (High)", command=lambda: send_high_command('3'))
button_3_high.pack()

button_3_low = tk.Button(command_frame, text="Stop pumpT2_T3 (Low)", command=lambda: send_low_command('3'))
button_3_low.pack()

button_s_high = tk.Button(command_frame, text="Start stirMotor (High)", command=lambda: send_high_command('S'))
button_s_high.pack()

button_s_low = tk.Button(command_frame, text="Stop stirMotor (Low)", command=lambda: send_low_command('S'))
button_s_low.pack()