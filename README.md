
# Snake Game Enhanced

A classic snake game with two unique modes: Classic and Survival. This game offers a nostalgic experience with a twist for players seeking an extra challenge.

## Features

- **Classic Mode**: 
  - Guide your snake to eat apples to grow in length and earn points.
  - The game ends if the snake collides with itself or with the walls.
  
- **Survival Mode**:
  - **Survival Points**: Gain points by surviving as long as possible, rather than collecting apples.
  - **Increasing Difficulty**: As time progresses, new wall obstacles appear randomly on the map.
  - **Moving Hazard**: Occasionally, a yellow bullet-like square moves horizontally across the map. Dodge it to stay alive.
  - **Power-Up**: Instead of apples, this mode features a rare power-up that grants temporary immortality, allowing you to pass through obstacles safely for a limited time.

## Screenshots


| <img width="310" alt="snake_menu" src="https://github.com/user-attachments/assets/821539fa-a124-4944-8755-22c2f73535cb"> | <img width="500" alt="snake_survival" src="https://github.com/user-attachments/assets/bcbe7769-d58c-4bce-b993-4baefeb82371"> |
|:---------------------------------------:|:---------------------------------------:|
| Snake Menu                | Survival Mode (paused)                          |



## Installation

#### Prerequisites

- **CMake** (version 3.15 or higher recommended)
- **SFML**
  - Ensure SFML is installed and accessible to CMake.

### Steps:

1. **Clone this repository**:

   ```bash
   git clone https://github.com/nmikolaj/snake-game-enhanced.git
   cd snake-game-enhanced
   ```

2. **Open the Project in an IDE**:

   Open your preferred IDE and import the project by selecting the `CMakeLists.txt` file in the project root directory.

3. **Configure the Project in the IDE**:

   Most IDEs will automatically detect the `CMakeLists.txt` file, configure the project and select the default compiler already available in the IDE.
   -  If the IDE does not detect CMakeLists.txt, set the path manually in the IDE's settings to CMakeLists.txt file.

5. **Build and Run the Project**:

   Use the IDE's build options to compile the project directly from the IDE.
   This should create executable file, which you can run from your build directory.

