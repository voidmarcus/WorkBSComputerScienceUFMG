library ieee;
use ieee.std_logic_1164.all;

entity async_counter_tb is
end entity async_counter_tb;

architecture async_counter_behavioral of async_counter_tb is
  constant  initial_time : time := 10 ms;
  constant 	clk_cycle : time  := 200 ms;

  signal mclk, mpren, mclrn : std_logic;

  component async_counter_top is
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

  async_counter_dut: async_counter_top port map(mclk, mpren, mclrn);

end architecture async_counter_behavioral;
