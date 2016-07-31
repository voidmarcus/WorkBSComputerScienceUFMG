library ieee;
use ieee.std_logic_1164.all;

entity sync_counter_tb is
end entity sync_counter_tb;

architecture sync_counter_behavioral of sync_counter_tb is
  constant  initial_time : time := 10 ms;
  constant  clk_cycle : time  := 200 ms;

  signal mclk, mpren, mclrn : std_logic;

  component sync_counter_top is
    port (
     clk, pren, clrn: in  std_logic
    );
  end component;

  begin
  
  initial_state: process 
  begin
    mpren <= '1';
    mclrn <= '0';
    wait for initial_time/2;
    mpren <= '1';
    mclrn <= '1';
    wait;
  end process;
  
  clk_gen: process
  begin
    mclk <= '1';
    wait for initial_time;
    loop
      mclk <= not mclk;
      wait for clk_cycle;
    end loop;
  end process;

  sync_counter_dut: sync_counter_top port map(mclk, mpren, mclrn);

end architecture sync_counter_behavioral;
