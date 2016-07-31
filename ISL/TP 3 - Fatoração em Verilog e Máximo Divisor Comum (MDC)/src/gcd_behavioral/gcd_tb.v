`timescale 1ns/100ps

module gcd_tb();
  reg clk;
  wire done;
  reg  [6:0]i, j;
  wire [6:0]disp[7:0];
  //wire [6:0]y;

  initial begin
    clk = 1'b0;
    i = 1;
    j = 1;
  end

  always begin
    #1 clk = ~clk;
  end

  always @(posedge clk) begin
    j = j + 1;
    if(j > 15) begin
      i = i + 1;
      j = 1;
      if(i > 15) begin
        i = 1;
        $finish;
      end
    end
    $display("%d %d", i, j);
  wait(done);
  //wait(!done);
  end

  gcd_top gcd_top_01(clk, {i, j}, done, disp[0], disp[1], disp[2], disp[3], disp[4], disp[5], disp[6], disp[7]);

  initial begin
    $dumpfile("gcd_tb.vcd");
    $dumpvars;
  end 
endmodule
