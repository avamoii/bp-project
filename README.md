# PacMan Game

### Fundamental Programming - Amirkabir University of Technology - Fall 2024

## Overview
This project is a **PacMan game** developed as part of the Fundamental Programming course. It is implemented in **C** using the **raylib** graphics library and **CMake** for building the project. The game features multiple screens, including a menu, gameplay, and score display, providing an engaging experience for players.

## Features
- **Menu Screen**: Displays options to Play, View Scores, or Exit the game.
- **Name Input Screen**: Allows players to input their name before starting the game.
- **Gameplay Screen**: Features the classic PacMan gameplay.
- **Ending Screen**: Displays the player's score, time played, and name after the game ends.
- **Score Screen**: Reads and displays the top 10 scores from a file, including player names, scores, time, and date.

### Screen Architecture
Each screen in the game is designed with four primary functions:

1. **init**: Initializes the screen's variables to their default values.
2. **update**: Updates the screen's state and handles user input. Called 60 times per second.
3. **draw**: Renders the screen based on its current state. Called 60 times per second.
4. **finish**:
   - **bool return type**: Determines if the screen should transition to the next screen.
   - **int return type**: Specifies the next screen to display.

## Prerequisites
- **CMake**: For building the project. Configured to automatically download the **raylib** library from GitHub.

## Installation and Setup
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/pacman-game.git
   cd pacman-game
   ```

2. Build the project using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Run the game:
   ```bash
   ./PacMan
   ```

## Screenshots
Here are some screenshots from different screens of the game:

<img width="1072" alt="image" src="https://github.com/user-attachments/assets/c229b4ac-a8ad-4c42-8c11-0ecd2525fd40" />
*Menu Screen: Displays options to Play, View Scores, or Exit.*

<img width="1072" alt="image" src="https://github.com/user-attachments/assets/7e014150-fc69-4981-aa25-f2b6dee26500" />

<img width="1072" alt="image" src="https://github.com/user-attachments/assets/d394b833-7377-4b1b-8ae5-cadc21acef83" />
*Gameplay Screen: Classic PacMan gameplay.*

<img width="1072" alt="image" src="https://github.com/user-attachments/assets/02f8d231-dd98-411e-904e-378198ad5134" />
*Ending Screen: Shows the player's score, time, and name.*

![Score Screen](path/to/score_screen.png)
*Score Screen: Displays the top 10 scores with details.*

## Contributing
Contributions are welcome! Please follow these steps:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Commit your changes with clear messages.
4. Submit a pull request.

## License
This project is licensed under the [MIT License](LICENSE).

## Acknowledgments
- **raylib**: For providing the graphics library.
- **CMake**: For simplifying the build process.

---

Feel free to explore, contribute, and share your feedback. Happy coding!
