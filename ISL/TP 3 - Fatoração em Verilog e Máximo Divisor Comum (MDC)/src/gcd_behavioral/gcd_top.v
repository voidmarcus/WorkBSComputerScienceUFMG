module gcd_top(CLOCK_50, SW, done, HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, HEX6, HEX7);
  input  CLOCK_50;                                            // main clock
  input  [17:0]SW;                                            // switches
  output [6:0]HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, HEX6, HEX7; // 7-seg disp
  output done;

  wire ack;
  wire [3:0]disp[5:0];
  wire [6:0]disp7[5:0];
  wire [6:0]r_old, a_xi, b_xi;

  reg rst, req;
  reg [6:0]r;
  reg [9:0]cnt0 = 0;
    
  always @(posedge CLOCK_50) begin
    if(cnt0 == 10) begin
  		rst = 1'b0;
	  	cnt0 = 10;
	  end else begin
      rst = 1'b1;
  		cnt0 = cnt0 + 1;
	  end

    if(rst) begin
      req = 1'b1;
      r = 0;
    end else begin
      if(req) 
        req = 1'b0;
      else
        if(ack) begin
          req = 1'b1;
          r = r_old;
        end
    end
  end

  assign done = ack;

  // input a:
  bin_to_bcd bin_to_bcd_01({1'b0, SW[13:7]}, disp[5], disp[4]);
  hex_to_7seg hex_to_7seg_01(disp[5], disp7[5]); // tens
  hex_to_7seg hex_to_7seg_02(disp[4], disp7[4]); // ones
  assign HEX7 = SW[13:7] == 0 || SW[13:7] > 99 ? 7'b0000110 : disp7[5];
  assign HEX6 = SW[13:7] == 0 || SW[13:7] > 99 ? 7'b0101111 : disp7[4];

  // input b:
  bin_to_bcd bin_to_bcd_02({1'b0, SW[6:0]}, disp[3], disp[2]);
  hex_to_7seg hex_to_7seg_03(disp[3], disp7[3]); // tens
  hex_to_7seg hex_to_7seg_04(disp[2], disp7[2]); // ones
  assign HEX5 = SW[6:0] == 0 || SW[6:0] > 99 ? 7'b0000110 : disp7[3];
  assign HEX4 = SW[6:0] == 0 || SW[6:0] > 99 ? 7'b0101111 : disp7[2];

  // turn off hundred's and thousand's displays:
  assign HEX3 = 7'b1111111;
  assign HEX2 = 7'b1111111;

  // output:
  bin_to_bcd bin_to_bcd_03({1'b0, r}, disp[1], disp[0]);
  hex_to_7seg hex_to_7seg_05(disp[1], disp7[1]); // tens
  hex_to_7seg hex_to_7seg_06(disp[0], disp7[0]); // ones
  assign HEX1 = SW[6:0]  == 0 || SW[6:0] > 99 || 
                SW[13:7] == 0 || SW[13:7] > 99 ? 7'b0000110 : disp7[1];
  assign HEX0 = SW[6:0]  == 0 || SW[6:0] > 99 || 
                SW[13:7] == 0 || SW[13:7] > 99 ? 7'b0101111 : disp7[0];

  // gcd engine:
  assign a_xi = SW[13:7] == 0 ? 1 : SW[13:7];
  assign b_xi = SW[6:0]  == 0 ? 1 : SW[6:0];
  gcd_engine gcd_engine_01(CLOCK_50, rst, req, a_xi, b_xi, ack, r_old);
endmodule

