library ieee;
use ieee.std_logic_1164.all;

entity async_counter_top is
  port (
    clk, pren, clrn: in  std_logic
  );
end entity async_counter_top;

architecture behavioral of async_counter_top is
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
  signal tmp:std_logic;
  signal disp_7seg : std_logic_vector(7 downto 0);
  signal disp_7seg_bcd : std_logic_vector(3 downto 0);

  begin 
  ff_jk0 : flipflop_jk port map(clk, pren, clrn, '1', '1', ff_q0, ff_qn0);
  ff_jk1 : flipflop_jk port map(ff_qn0, pren, clrn, '1', '1', ff_q1, ff_qn1);
  ff_jk2 : flipflop_jk port map(ff_qn1, pren, clrn, '1', '1', ff_q2, tmp);
  disp_7seg_bcd <= '0' & ff_q2 & ff_q1 & ff_q0;
  bcd_7seg_dec0 : dec_bcd_to_7seg port map(disp_7seg_bcd, disp_7seg);
end architecture behavioral;
