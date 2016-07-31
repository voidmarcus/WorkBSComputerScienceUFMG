module fatorador_top (CLOCK_50, SW, HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, HEX6, HEX7);
  input CLOCK_50;                                              // clock signal
  input  [15:0]SW;                                             // value to factorize 
  output [6:0]HEX0, HEX1, HEX2, HEX3, HEX4, HEX5, HEX6, HEX7;  // outputs display's

  wire ack;
  wire [3:0]dd0, dd1, dd2, dd3, dd4, dd5, dd6, dd7;
  reg  rst, req;
  integer cnt = 0;
  wire [15:0]disp0, disp1, disp2, disp3;
  
  always @(posedge CLOCK_50) begin
    if(cnt == 10) begin
      rst = 0;
      cnt = 10;
    end else begin
      rst = 1;
      cnt = cnt + 1;
    end
/*
    if(rst) begin
      req = 1;
    end else begin
      if(req) 
        req = 0;
      else
        if(ack) begin
          req = 1;
        end
    end
*/
  end

  //assign ready = ack;
  fatorador_engine fatorador_engine_00(CLOCK_50, rst, req, SW, ack, disp0, disp1, disp2, disp3);

  bin_to_bcd bin_to_bcd_01(disp0, dd1, dd0);
  hex_to_7seg hex_to_7seg_00(dd0, HEX0);    // tens
  hex_to_7seg hex_to_7seg_01(dd1, HEX1);    // ones

  bin_to_bcd bin_to_bcd_02(disp1, dd3, dd2);
  hex_to_7seg hex_to_7seg_02(dd2, HEX2);    // tens
  hex_to_7seg hex_to_7seg_03(dd3, HEX3);    // ones

  bin_to_bcd bin_to_bcd_03(disp2, dd5, dd4);
  hex_to_7seg hex_to_7seg_04(dd4, HEX4);    // tens
  hex_to_7seg hex_to_7seg_05(dd5, HEX5);    // ones

  bin_to_bcd bin_to_bcd_04(disp3, dd7, dd6);
  hex_to_7seg hex_to_7seg_06(dd6, HEX6);    // tens
  hex_to_7seg hex_to_7seg_07(dd7, HEX7);    // ones
endmodule
