library ieee;
use ieee.std_logic_1164.all;

entity flipflop_jk is
  port (
    clk, pren, clrn, j, k: in  std_logic;
    q, qn: out std_logic
  );
end entity flipflop_jk;

architecture rtl of flipflop_jk is
  signal tmp_q, tmp_qn : std_logic;
  signal jk : std_logic_vector(1 downto 0) := "00";
  begin 
  jk <= j & k;
  ff_jk : process(clk, pren, clrn)
  begin
    if(pren = '0' and clrn = '1') then 
      tmp_q  <= '1';
      tmp_qn <= '0';
    elsif(pren = '1' and clrn = '0') then 
      tmp_q  <= '0';
      tmp_qn <= '1';
    elsif(pren = '0' and clrn = '0') then 
      tmp_q  <= '1';
      tmp_qn <= '1';
    elsif(pren = '1' and clrn = '1') then
      if(rising_edge(clk)) then
        case jk is
          when "00" =>
            tmp_q  <= tmp_q;
            tmp_qn <= tmp_qn;
          when "01" =>
            tmp_q  <= '0';
            tmp_qn <= '1';
          when "10" =>
            tmp_q  <= '1';
            tmp_qn <= '0';
          when "11" =>
            tmp_q  <= not tmp_q;
            tmp_qn <= not tmp_qn;
          when others =>
            tmp_q  <= tmp_q;
            tmp_qn <= tmp_qn;
        end case;
      end if;    
    end if;
  end process;
  q  <= tmp_q;
  qn <= tmp_qn;
end architecture rtl;
