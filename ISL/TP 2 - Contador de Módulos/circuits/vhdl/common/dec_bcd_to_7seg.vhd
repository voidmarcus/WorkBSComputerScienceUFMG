library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;

entity dec_bcd_to_7seg is
  port (
    bcd:        in  std_logic_vector(3 downto 0);
    seven_segs: out std_logic_vector(7 downto 0)
  );
end entity dec_bcd_to_7seg;

architecture rtl of dec_bcd_to_7seg is
  begin 
  bcd_to_7seg : process(bcd) begin
    case bcd is
      when "0000" => seven_segs <= x"01";
      when "0001" => seven_segs <= x"67";
      when "0010" => seven_segs <= x"12";
      when "0011" => seven_segs <= x"42";

      when "0100" => seven_segs <= x"64";
      when "0101" => seven_segs <= x"48";
      when "0110" => seven_segs <= x"0c";
      when "0111" => seven_segs <= x"63";

      when "1000" => seven_segs <= x"00";
      when "1001" => seven_segs <= x"60";
      when "1010" => seven_segs <= x"1e";
      when "1011" => seven_segs <= x"4e";

      when "1100" => seven_segs <= x"74";
      when "1101" => seven_segs <= x"58";
      when "1110" => seven_segs <= x"1c";
      when others => seven_segs <= x"7f";
    end case;
  end process;
end architecture rtl;
