-- ==============================================================
-- RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
-- Version: 2022.2
-- Copyright (C) Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity Radix2wECC_Radix2wECC_Pipeline_VITIS_LOOP_23_124 is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    p_Val2_52 : IN STD_LOGIC_VECTOR (165 downto 0);
    p_Val2_53 : IN STD_LOGIC_VECTOR (165 downto 0);
    p_Val2_54_out : OUT STD_LOGIC_VECTOR (165 downto 0);
    p_Val2_54_out_ap_vld : OUT STD_LOGIC );
end;


architecture behav of Radix2wECC_Radix2wECC_Pipeline_VITIS_LOOP_23_124 is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv8_0 : STD_LOGIC_VECTOR (7 downto 0) := "00000000";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv8_A6 : STD_LOGIC_VECTOR (7 downto 0) := "10100110";
    constant ap_const_lv8_1 : STD_LOGIC_VECTOR (7 downto 0) := "00000001";
    constant ap_const_boolean_1 : BOOLEAN := true;

attribute shreg_extract : string;
    signal ap_CS_fsm : STD_LOGIC_VECTOR (0 downto 0) := "1";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal ap_block_state1_pp0_stage0_iter0 : BOOLEAN;
    signal icmp_ln23_fu_73_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_condition_exit_pp0_iter0_stage0 : STD_LOGIC;
    signal ap_loop_exit_ready : STD_LOGIC;
    signal ap_ready_int : STD_LOGIC;
    signal i_fu_38 : STD_LOGIC_VECTOR (7 downto 0);
    signal i_48_fu_79_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal ap_loop_init : STD_LOGIC;
    signal ap_sig_allocacmp_i_47 : STD_LOGIC_VECTOR (7 downto 0);
    signal p_Val2_s_fu_42 : STD_LOGIC_VECTOR (165 downto 0);
    signal p_Result_50_fu_114_p4 : STD_LOGIC_VECTOR (165 downto 0);
    signal index_assign_25_cast_fu_88_p1 : STD_LOGIC_VECTOR (31 downto 0);
    signal p_Result_s_fu_92_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal p_Result_49_fu_100_p3 : STD_LOGIC_VECTOR (0 downto 0);
    signal xor_ln24_fu_108_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_done_reg : STD_LOGIC := '0';
    signal ap_continue_int : STD_LOGIC;
    signal ap_done_int : STD_LOGIC;
    signal ap_NS_fsm : STD_LOGIC_VECTOR (0 downto 0);
    signal ap_ST_fsm_state1_blk : STD_LOGIC;
    signal ap_start_int : STD_LOGIC;
    signal ap_ce_reg : STD_LOGIC;

    component Radix2wECC_flow_control_loop_pipe_sequential_init IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_start_int : OUT STD_LOGIC;
        ap_loop_init : OUT STD_LOGIC;
        ap_ready_int : IN STD_LOGIC;
        ap_loop_exit_ready : IN STD_LOGIC;
        ap_loop_exit_done : IN STD_LOGIC;
        ap_continue_int : OUT STD_LOGIC;
        ap_done_int : IN STD_LOGIC );
    end component;



begin
    flow_control_loop_pipe_sequential_init_U : component Radix2wECC_flow_control_loop_pipe_sequential_init
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => ap_start,
        ap_ready => ap_ready,
        ap_done => ap_done,
        ap_start_int => ap_start_int,
        ap_loop_init => ap_loop_init,
        ap_ready_int => ap_ready_int,
        ap_loop_exit_ready => ap_condition_exit_pp0_iter0_stage0,
        ap_loop_exit_done => ap_done_int,
        ap_continue_int => ap_continue_int,
        ap_done_int => ap_done_int);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    ap_done_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_done_reg <= ap_const_logic_0;
            else
                if ((ap_continue_int = ap_const_logic_1)) then 
                    ap_done_reg <= ap_const_logic_0;
                elsif (((ap_loop_exit_ready = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start_int = ap_const_logic_1))) then 
                    ap_done_reg <= ap_const_logic_1;
                end if; 
            end if;
        end if;
    end process;


    i_fu_38_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start_int = ap_const_logic_1))) then
                if ((icmp_ln23_fu_73_p2 = ap_const_lv1_0)) then 
                    i_fu_38 <= i_48_fu_79_p2;
                elsif ((ap_loop_init = ap_const_logic_1)) then 
                    i_fu_38 <= ap_const_lv8_0;
                end if;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln23_fu_73_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start_int = ap_const_logic_1))) then
                p_Val2_s_fu_42 <= p_Result_50_fu_114_p4;
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_CS_fsm, ap_CS_fsm_state1, ap_start_int)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                ap_NS_fsm <= ap_ST_fsm_state1;
            when others =>  
                ap_NS_fsm <= "X";
        end case;
    end process;
    ap_CS_fsm_state1 <= ap_CS_fsm(0);

    ap_ST_fsm_state1_blk_assign_proc : process(ap_start_int)
    begin
        if ((ap_start_int = ap_const_logic_0)) then 
            ap_ST_fsm_state1_blk <= ap_const_logic_1;
        else 
            ap_ST_fsm_state1_blk <= ap_const_logic_0;
        end if; 
    end process;


    ap_block_state1_pp0_stage0_iter0_assign_proc : process(ap_start_int)
    begin
                ap_block_state1_pp0_stage0_iter0 <= (ap_start_int = ap_const_logic_0);
    end process;


    ap_condition_exit_pp0_iter0_stage0_assign_proc : process(ap_CS_fsm_state1, icmp_ln23_fu_73_p2, ap_start_int)
    begin
        if (((icmp_ln23_fu_73_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start_int = ap_const_logic_1))) then 
            ap_condition_exit_pp0_iter0_stage0 <= ap_const_logic_1;
        else 
            ap_condition_exit_pp0_iter0_stage0 <= ap_const_logic_0;
        end if; 
    end process;


    ap_done_int_assign_proc : process(ap_CS_fsm_state1, ap_loop_exit_ready, ap_done_reg, ap_start_int)
    begin
        if (((ap_loop_exit_ready = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start_int = ap_const_logic_1))) then 
            ap_done_int <= ap_const_logic_1;
        else 
            ap_done_int <= ap_done_reg;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_CS_fsm_state1, ap_start_int)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start_int = ap_const_logic_0))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;

    ap_loop_exit_ready <= ap_condition_exit_pp0_iter0_stage0;

    ap_ready_int_assign_proc : process(ap_CS_fsm_state1, ap_start_int)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start_int = ap_const_logic_1))) then 
            ap_ready_int <= ap_const_logic_1;
        else 
            ap_ready_int <= ap_const_logic_0;
        end if; 
    end process;


    ap_sig_allocacmp_i_47_assign_proc : process(ap_CS_fsm_state1, i_fu_38, ap_loop_init)
    begin
        if (((ap_loop_init = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_sig_allocacmp_i_47 <= ap_const_lv8_0;
        else 
            ap_sig_allocacmp_i_47 <= i_fu_38;
        end if; 
    end process;

    i_48_fu_79_p2 <= std_logic_vector(unsigned(ap_sig_allocacmp_i_47) + unsigned(ap_const_lv8_1));
    icmp_ln23_fu_73_p2 <= "1" when (ap_sig_allocacmp_i_47 = ap_const_lv8_A6) else "0";
    index_assign_25_cast_fu_88_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(ap_sig_allocacmp_i_47),32));
    p_Result_49_fu_100_p3 <= p_Val2_53(to_integer(unsigned(index_assign_25_cast_fu_88_p1)) downto to_integer(unsigned(index_assign_25_cast_fu_88_p1))) when (to_integer(unsigned(index_assign_25_cast_fu_88_p1)) >= 0 and to_integer(unsigned(index_assign_25_cast_fu_88_p1)) <=165) else "-";
    
    p_Result_50_fu_114_p4_proc : process(p_Val2_s_fu_42, index_assign_25_cast_fu_88_p1, xor_ln24_fu_108_p2)
    begin
        p_Result_50_fu_114_p4 <= p_Val2_s_fu_42;
        if to_integer(unsigned(index_assign_25_cast_fu_88_p1)) >= p_Val2_s_fu_42'low and to_integer(unsigned(index_assign_25_cast_fu_88_p1)) <= p_Val2_s_fu_42'high then
            p_Result_50_fu_114_p4(to_integer(unsigned(index_assign_25_cast_fu_88_p1))) <= xor_ln24_fu_108_p2(0);
        end if;
    end process;

    p_Result_s_fu_92_p3 <= p_Val2_52(to_integer(unsigned(index_assign_25_cast_fu_88_p1)) downto to_integer(unsigned(index_assign_25_cast_fu_88_p1))) when (to_integer(unsigned(index_assign_25_cast_fu_88_p1)) >= 0 and to_integer(unsigned(index_assign_25_cast_fu_88_p1)) <=165) else "-";
    p_Val2_54_out <= p_Val2_s_fu_42;

    p_Val2_54_out_ap_vld_assign_proc : process(ap_CS_fsm_state1, icmp_ln23_fu_73_p2, ap_start_int)
    begin
        if (((icmp_ln23_fu_73_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start_int = ap_const_logic_1))) then 
            p_Val2_54_out_ap_vld <= ap_const_logic_1;
        else 
            p_Val2_54_out_ap_vld <= ap_const_logic_0;
        end if; 
    end process;

    xor_ln24_fu_108_p2 <= (p_Result_s_fu_92_p3 xor p_Result_49_fu_100_p3);
end behav;
