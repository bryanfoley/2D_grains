void set_static_positions(double wall_particle[44][m_max][z_max],double rad)
{
     int i;
     char func_name[35] = "set_static_positions";
     char action_begin[10] = ">>>";
     char action_end[10] = "<<<";
     time_stamp();
     trace(func_name,action_begin);
/*________________________________BOTTOM ROW__________________________________*/     
     /*Set the FIRST BOTTOM ROW particle, right edge, at x = -5.0*/
     wall_particle[0][2][0] = -5.5;
     
     /*Set ALL BOTTOM ROW particles at y = 0.0*/
     for(i = 0; i < 22; i++)
      {
       wall_particle[i][3][0] = 0.0000000000000000;
      }
     
     /*Set the REMAINING BOTTOM ROW particles an equal x-distance apart*/
     for(i = 1; i < 22; i++)
      {
       wall_particle[i][2][0] = ((wall_particle[i-1][2][0]) + 1.0);
      }
/*_________________________________TOP ROW____________________________________*/      
     /*Set the FIRST TOP ROW particle, right edge, at x = -5.0*/
     wall_particle[22][2][0] = -5.5;
     
     /*Set ALL TOP ROW particles at y = 32.0*/
     for(i = 22; i < 44; i++)
      {
       wall_particle[i][3][0] = 32.0;
      }
     
     /*Set the REMAINING TOP ROW particles an equal x-distance apart*/
     for(i = 23; i < 44; i++)
      {
       wall_particle[i][2][0] = ((wall_particle[i-1][2][0]) + 1.0);
      }
     time_stamp();
     trace(func_name,action_end);
}
