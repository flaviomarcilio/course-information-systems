// testbench
module ShiftRegister_8bit_test;
  reg [287:0]msg; // Mensagem a ser cifrada
  reg [287:0]result; // Resultado da cifragem e decifragem
  
  reg [7:0]otp; // One-Time-Pad
  reg sh_enc;
  reg sh_dec;
  reg load;
  reg clk;
  wire serial_out_enc;
  wire serial_out_dec;
  
  integer i;
  
  // Instanciando o Registrador para cifrar a mensagem
  ShiftRegister_8bit enc(.data(otp), .sh(sh_enc), .load(load), .clk(clk),
                         .serial_out(serial_out_enc));
  
  // Instanciando o Registrador para decifrar a mensagem
  ShiftRegister_8bit dec(.data(otp), .sh(sh_enc), .load(load), .clk(clk),
                         .serial_out(serial_out_dec));

  initial 
    begin
  	  clk = 1'b0;
      forever #10 clk = ~clk;  
   	end

  initial
    begin
      $dumpfile("dump.vcd");
      $dumpvars(1, ShiftRegister_8bit_test);
      // msg <= Universidade Federal de Minas Gerais
      msg <= 288'b010101010110111001101001011101100110010101110010011100110110100101100100011000010110010001100101001000000100011001100101011001000110010101110010011000010110110000100000011001000110010100100000010011010110100101101110011000010111001100100000010001110110010101110010011000010110100101110011;
      otp <= 8'b00101010;
      sh_enc <= 0;
      sh_dec <= 0;
      load <= 1;
      
      #10
      $display("Mensagem Original: %36s", msg);
      $display("One-Time-Pad     : %b", otp);
      $display("\nCifrando...");
      sh_enc <= 1;
      load <= 0;
      
      for (i = 0; i < 288; i = i + 1) begin
        #20
        result[i] <= msg[i] ^ serial_out_enc;
      end
      
      $display("Mensagem Cifrada: %36s", result);
      

      $display("\nDecifrando...");
      sh_dec <= 1;

      for (i = 0; i < 288; i = i + 1) begin
        #20
        result[i] <= result[i] ^ serial_out_dec;
      end
      
      $display("Mensagem Decifrada: %36s", result);
      
      #10
      $finish;
    end 
endmodule