library ieee;
use ieee.std_logic_1164.all;

entity sync_counter_top is
  port (
    clk, pren, clrn: in  std_logic
  );
end entity sync_counter_top;

architecture behavioral of sync_counter_top is
  component dec_bcd_to_7seg is
    port (
      bcd:        in  std_logic_vector(3 downto 0);
      seven_segs: out std_logic_vector(7 downto 0)
    );
  end component;

  component flipflop_jk is
    port (
      clk, pren, clrn, j, k: in  std_logic;
      q, qn: out std_logic
    );
  end component;  

  signal ff_q0, ff_qn0, ff_q1, ff_qn1, ff_q2 : std_logic;
  signal clearff, and1 : std_logic;
  signal disp_7seg : std_logic_vector(7 downto 0);
  signal disp_7seg_bcd : std_logic_vector(3 downto 0);

  begin 
  and1 <= ff_q0 and ff_q1;
  clearff <= clrn and not(ff_q1 and ff_q2);
  disp_7seg_bcd <= '0' & ff_q2 & ff_q1 & ff_q0;
  ff_jk0 : flipflop_jk port map(clk, pren, clearff, '1', '1', ff_q0, ff_qn0);
  ff_jk1 : flipflop_jk port map(clk, pren, clearff, ff_q0, ff_q0, ff_q1, ff_qn1);
  ff_jk2 : flipflop_jk port map(clk, pren, clearff, and1, and1, ff_q2);
  bcd_7seg_dec0 : dec_bcd_to_7seg port map(disp_7seg_bcd, disp_7seg);
end architecture behavioral;
