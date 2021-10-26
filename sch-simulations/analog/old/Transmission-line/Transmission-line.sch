<Qucs Schematic 0.0.19>
<Properties>
  <View=0,0,882,800,1,0,0>
  <Grid=10,10,1>
  <DataSet=Transmission_line.dat>
  <DataDisplay=Transmission_line.dpl>
  <OpenDisplay=1>
  <Script=Transmission_line.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <GND * 1 120 270 0 0 0 0>
  <Switch S1 1 680 180 -26 11 0 0 "off" 0 "1 ms" 0 "0" 0 "1e12" 0 "26.85" 0 "1e-6" 0 "spline" 0>
  <R R1 1 770 180 -26 15 0 0 "50 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <Switch S2 1 770 120 -26 11 0 0 "off" 0 "1 ms" 0 "0" 0 "1e12" 0 "26.85" 0 "1e-6" 0 "spline" 0>
  <Vpulse V1 1 120 210 18 -26 0 1 "0 V" 1 "1 V" 1 "0" 1 "5 ns" 1 "1 ns" 0 "1 ns" 0>
  <.TR TR1 1 130 30 0 51 0 0 "lin" 1 "0" 1 "5 us" 1 "100" 0 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
  <TLIN Line1 1 230 180 -26 20 0 0 "50 Ohm" 1 "2000 mm" 1 "0 dB" 0 "26.85" 0>
  <TLIN Line2 1 330 180 -26 20 0 0 "50 Ohm" 1 "2000 mm" 1 "0 dB" 0 "26.85" 0>
  <TLIN Line3 1 430 180 -26 20 0 0 "50 Ohm" 1 "2000 mm" 1 "0 dB" 0 "26.85" 0>
  <TLIN Line4 1 530 180 -26 20 0 0 "50 Ohm" 1 "2000 mm" 1 "0 dB" 0 "26.85" 0>
</Components>
<Wires>
  <260 180 300 180 "" 0 0 0 "">
  <360 180 400 180 "l_2" 410 150 16 "">
  <460 180 500 180 "l_4" 520 150 25 "">
  <120 180 200 180 "in" 160 150 5 "">
  <120 240 120 270 "" 0 0 0 "">
  <560 180 650 180 "" 0 0 0 "">
  <710 180 740 180 "load" 730 60 15 "">
  <740 120 740 180 "" 0 0 0 "">
  <800 120 800 180 "" 0 0 0 "">
  <800 180 840 180 "" 0 0 0 "">
  <120 270 120 280 "" 0 0 0 "">
  <120 280 840 280 "" 0 0 0 "">
  <840 180 840 280 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
