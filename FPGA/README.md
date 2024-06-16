**FPGA Implementation of Vending machine:**

#### Objective

The objective of the project is to simulate and implement a vending machine using an FPGA kit and Xilinx Vivado software. The FPGA-based vending machine is designed to offer an efficient, reliable, and flexible solution for dispensing products, handling transactions, and managing inventory. It aims to enhance traditional vending machine functionalities by leveraging FPGA technology for improved performance, flexibility, and integration of advanced features.

#### Key Learnings

1. **FPGA-Based Design and Implementation**:
    - **Module Creation**: Developed a Verilog module for the vending machine, defining inputs for item selection and coins, and outputs for dispensing items and returning change.
    - **Hardware Integration**: Configured the FPGA hardware using Xilinx Vivado, including pin assignments and constraint files for input and output connections.
2. **Transaction Handling**:
    - **Item Selection and Pricing**: Implemented a system where different products are selected using a 2-bit input (select) and each product has a specific price (ITEM1_PRICE, ITEM2_PRICE, ITEM3_PRICE).
    - **Coin Insertion and Validation**: Designed logic to compare inserted coins (coin_in) against item prices and determine if enough coins are inserted to dispense the selected item.
3. **Dispense Logic and Change Calculation**:
    - **Dispensing Products**: Created logic to dispense items if sufficient coins are inserted and set the dispense signal accordingly.
    - **Returning Change**: Added functionality to calculate and signal if change needs to be returned (change), ensuring any excess coins are properly managed.
4. **Simulation and Testing**:
    - **Behavioral Simulation**: Used Xilinx Vivado's simulation tools to test the vending machine’s behavior and validate the functionality of the Verilog code before actual implementation.
    - **RTL Analysis**: Analyzed the synthesized design to ensure correctness in logic and functionality through the elaborated design and schematic window in Vivado.
5. **Technological Integration**:
    - **Cashless Payments and Monitoring**: Explored the integration of advanced features like cashless payment systems and remote monitoring, enhancing the usability and efficiency of the vending machine.
    - **Adaptability**: Recognized the adaptability of FPGA systems to incorporate new functionalities and updates without major hardware changes.
6. **FPGA Advantages**:
    - **Efficiency**: Observed significant improvements in transaction processing speed and reliability compared to traditional microcontroller-based vending machines.
    - **Cost-Effectiveness**: Noted the reduced costs due to FPGA’s robustness, flexibility, and lower maintenance requirements.
7. **Practical Applications**:
    - **Inventory Management**: Highlighted how FPGA-based systems offer accurate and real-time tracking of stock levels, improving inventory management.
    - **Customization and Scalability**: Emphasized the ability to easily reprogram and scale the system for different products and configurations, making it adaptable for various vending scenarios.
8. **Methodology**:
    - **Design Flow**: Followed a systematic approach including creating the project, entering code, simulating, synthesizing, and finally implementing the design on the FPGA hardware.
    - **I/O Planning and Constraints**: Managed I/O planning and constraints efficiently within Vivado to match the hardware pinout requirements.
9. **Team Collaboration**:
    - **Project Management**: Coordinated among team members for designing, coding, testing, and documenting the project, ensuring effective collaboration and project completion.

**FPGA Implementation of Traffic light controller:**

**Objective:**

The objective of this case study is to design and implement a traffic light controller for a T-shaped intersection using an FPGA (Field-Programmable Gate Array). The implementation aims to regulate traffic flow efficiently through this intersection, managing different traffic loads and directions using a state machine approach. The design uses Xilinx Vivado software and an FPGA kit to create and test the traffic light controller.

**Key Learnings:**

1. **State Machine Design**:
    - **Understanding State Machines**: The project involved designing a state machine with six states (S1, S2, S3, S4, S5, S6) to control the traffic lights. Each state represented a different configuration of traffic lights, managing the traffic flow in various directions.
    - **State Transitions**: The transitions between states were based on time delays specific to each state, indicating when lights should change from green to yellow to red.
2. **Traffic Flow Management**:
    - **Signal Timing**: Different timings for each signal state (TMG, TY, TTG, TSG) were considered to simulate realistic traffic conditions and transitions.
    - **Signal States**:
        - **Green (G)** indicates free flow of traffic.
        - **Yellow (Y)** signals a warning before a change.
        - **Red (R)** indicates a stop to allow traffic in another direction.
3. **FPGA Implementation**:
    - **Programming**: The project involved writing Verilog code to program the FPGA, defining the logic for each state and the transitions based on the input clock and reset signals.
    - **Simulation and Testing**: The design was simulated using Xilinx Vivado to verify the correctness of the traffic light controller before actual implementation on the FPGA hardware.
4. **Use of Xilinx Vivado**:
    - **Simulation Tools**: Xilinx Vivado software provided tools for simulating the state machine, allowing the design to be tested and debugged before deployment.
    - **FPGA Configuration**: Vivado was used to configure the FPGA, including generating the bitstream for programming the FPGA with the traffic controller logic.
5. **System Analysis**:
    - **Traffic Patterns**: The project included an analysis of typical traffic patterns at the intersection, designing the state machine to efficiently handle varying traffic loads.
    - **State Table and Diagram**: The use of state tables and diagrams helped in visualizing the behavior of the system and planning the logic for traffic control.
6. **Practical Applications**:
    - **Real-World Relevance**: The traffic light controller system designed is representative of real-world applications where FPGA-based controllers are used in traffic management systems for intersections.
    - **Scalability**: The principles learned can be scaled and adapted for more complex intersections and traffic conditions.
7. **Technical Skills Development**:
    - **Verilog Coding**: Enhanced proficiency in Verilog, essential for FPGA programming.
    - **Hardware-Software Integration**: Gained experience in integrating software design with hardware implementation using FPGAs.
8. **Team Collaboration**:
    - **Project Management**: Collaboration in defining roles, designing the system, and testing the implementation contributed to effective project management.
    - **Documentation and Reporting**: The importance of documenting the design process, testing procedures, and results was emphasized, culminating in the case study report.
