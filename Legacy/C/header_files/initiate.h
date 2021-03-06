void initiate( double free_particle[n_max][m_max][z_max],
               double image_free_particle[n_max][m_max][z_max],
               double wall_particle[44][m_max][z_max],
               double free_forces[n_max][n_max][z_max],
               double image_free_forces[n_max][n_max][z_max],
               double wall_free_forces[n_max][44][z_max],
               double image_image_forces[n_max][n_max][z_max],
               double wall_image_forces[n_max][44][z_max],
               double x[n_max][n_max],
               double image_x[n_max][n_max],
               double wall_x[n_max][44],
               double image_image_x[n_max][n_max],
               double wall_image_x[n_max][44])
{
     /*Counters*/
     int i,j,l,m,n,z;
     char func_name[30] = "initiate";
     char action_begin[10] = ">>>";
     char action_end[10] = "<<<";
     time_stamp();
     trace(func_name,action_begin);
     

      /*Set PARTICLE ARRAYS to zero*/
      for(n = 0; n < (n_max); n++)
       {
        for(m = 0; m < (m_max); m++)
         {
          for(z = 0; z < (z_max); z++)
           {
            free_particle[n][m][z] = 0.0000000000000000;
            image_free_particle[n][m][z] = 0.0000000000000000;
           }
         }
       }
     
     
     /*Set WALL PARTICLE ARRAYS to zero*/
     for(n = 0; n < (44); n++)
       {
        for(m = 0; m < (m_max); m++)
         {
          for(z = 0; z < (z_max); z++)
           {
            wall_particle[n][m][z] = 0.0000000000000000;
           }
         }
       }
     
     
     /*Set FORCES ARRAYS to zero*/
     for(n = 0; n < (n_max); n++)
      {
       for(m = 0; m < (n_max); m++)
        {
         for(z = 0; z < (z_max); z++)
         {
          free_forces[n][m][z] = 0.0000000000000000;
          image_free_forces[n][m][z] = 0.0000000000000000;
          image_image_forces[n][m][z] = 0.0000000000000000;
         }
        }
      }
     
     
     /*Set WALL FORCES ARRAYS to zero*/
     for(n = 0; n < (n_max); n++)
      {
       for(m = 0; m < (44); m++)
        {
         for(z = 0; z < (z_max); z++)
         {
          wall_free_forces[n][m][z] = 0.0000000000000000;
          wall_image_forces[n][m][z] = 0.0000000000000000;
         }
        }
      }
     
     
     /*Set SEPERATION ARRAYS to zero*/
     for(i = 0; i < (n_max); i++)
      {
       for(j = 0; j < (n_max); j++)
        {
         x[i][j] = 0.0000000000000000;
         image_x[i][j] = 0.0000000000000000;
         image_image_x[i][j] = 0.0000000000000000;
        }
      }
     
     
     /*Set WALL SEPERATION ARRAYS to zero*/
     for(i = 0; i < (n_max); i++)
      {
       for(j = 0; j < (44); j++)
        {
         wall_x[i][j] = 0.0000000000000000;
         wall_image_x[i][j] = 0.0000000000000000;
        }
      }
     

     /*Set image_free_particles at an arbitrary distance*/
     for(n = 0; n < (n_max); n++)
       {
        for(z = 0; z < (z_max); z++)
         {
          image_free_particle[n][2][z] = 30.0000000000000000 + rand();
          image_free_particle[n][3][z] = 30.0000000000000000 + rand();
         }
       }
       
     /*Set the wall_particle velocity, of the top row, to -1e-3 in the y direction*/
     for(i = 22; i < 44; i++)
      {
       wall_particle[i][1][0] = wall_speed;
      }
     printf("Done initialising!\n");
     time_stamp();
     trace(func_name,action_end);
}
