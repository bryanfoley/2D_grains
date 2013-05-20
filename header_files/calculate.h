void calculate(double free_particle[n_max][m_max][z_max],
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
     int i, j;
     double nx,ny,R1R2,r1r2,red_mass,rel_vel_x,rel_vel_y;
     char func_name[30] = "calculate";
     char action_begin[10] = ">>>";
     char action_end[10] = "<<<";
     time_stamp();
     trace(func_name,action_begin);
     
     /*Reset the Coordination number to zero for all free_particles*/
     for(i = 0; i < n_max; i++)
      {
       free_particle[i][10][0] = 0.0;
       image_free_particle[i][10][0] = 0.0;
      }
      
     for(i = 0; i < 44; i++)
      {
       wall_particle[i][10][0] = 0.0;
      }
/*____________________________________________________________________________*/     
     /*Detect a collison between two free_particles*/
     for (i = 0; i < n_max; i++)
      {
       for (j = i+1; j < n_max; j++)
        {
         R1R2 = free_particle[i][9][0] + free_particle[j][9][0];
         
         r1r2 = sqrt((pow((free_particle[j][2][0] - free_particle[i][2][0]),2.0000000000000000))
                +(pow((free_particle[j][3][0] - free_particle[i][3][0]),2.0000000000000000)));
         
         red_mass = ((free_particle[i][8][0]*free_particle[j][8][0])/(free_particle[i][8][0] + free_particle[j][8][0]));
         
         rel_vel_x = (free_particle[i][0][0] - free_particle[j][0][0]);
         
         rel_vel_y = (free_particle[i][1][0] - free_particle[j][1][0]);
                                               
         if(r1r2 < R1R2)
          {
           /*Increase the Coordination Number by 1.0 for each collision*/
           free_particle[i][10][0] += 1.0;
           free_particle[j][10][0] += 1.0;
           
           /*Normal force x, component*/
           nx = (free_particle[i][2][0] - free_particle[j][2][0])/r1r2;
           /*Normal force y, component*/
           ny = (free_particle[i][3][0] - free_particle[j][3][0])/r1r2;
           
           /*Overlap distance of the two free_particles*/
           x[i][j] = R1R2 - r1r2;
                       
           /*Repulsive Force, x component*/  
           free_forces[i][j][0] = ((kn*(x[i][j]))-((gamma*red_mass)*(rel_vel_x*nx)))*nx;
           /*Repulsive Force, y component*/
           free_forces[i][j][1] = ((kn*(x[i][j]))-((gamma*red_mass)*(rel_vel_y*ny)))*ny;
          }
         else
          {
           free_particle[i][10][0] += 0.0;
           free_particle[j][10][0] += 0.0;
           nx = 0.0000000000000000;
           ny = 0.0000000000000000;
           x[i][j] = 0.0000000000000000;          /*Separation between centres*/
           free_forces[i][j][0] = 0.0000000000000000;/*Repulsive force, x component*/
           free_forces[i][j][1] = 0.0000000000000000;/*Repulsive force, y component*/
          }
                                               
         /*Use the symmetry of free_forces to reduce the number of calculations*/
         free_forces[j][i][0] = -(free_forces[i][j][0]);
         free_forces[j][i][1] = -(free_forces[i][j][1]);
         x[j][i] = x[i][j];
        }
      }
/*____________________________________________________________________________*/           
      /*Detect a collison between two image_free_particles*/
     for (i = 0; i < n_max; i++)
      {
       for (j = i+1; j < n_max; j++)
        {
         R1R2 = image_free_particle[i][9][0] + image_free_particle[j][9][0];
         
         r1r2 = sqrt((pow((image_free_particle[j][2][0] - image_free_particle[i][2][0]),2.0000000000000000))
                +(pow((image_free_particle[j][3][0] - image_free_particle[i][3][0]),2.0000000000000000)));
         
         red_mass = ((image_free_particle[i][8][0]*image_free_particle[j][8][0])/(image_free_particle[i][8][0] + image_free_particle[j][8][0]));
         
         rel_vel_x = (image_free_particle[i][0][0] - image_free_particle[j][0][0]);
         
         rel_vel_y = (image_free_particle[i][1][0] - image_free_particle[j][1][0]);
                                               
         if(r1r2 < R1R2)
          {
           /*Normal force x, component*/
           nx = (image_free_particle[i][2][0] - image_free_particle[j][2][0])/r1r2;
           /*Normal force y, component*/
           ny = (image_free_particle[i][3][0] - image_free_particle[j][3][0])/r1r2;
           
           /*Overlap distance of the two free_particles*/
           image_image_x[i][j] = R1R2 - r1r2;
                       
           /*Repulsive Force, x component*/  
           image_image_forces[i][j][0] = ((kn*(image_image_x[i][j]))-((gamma*red_mass)*(rel_vel_x*nx)))*nx;
           /*Repulsive Force, y component*/
           image_image_forces[i][j][1] = ((kn*(image_image_x[i][j]))-((gamma*red_mass)*(rel_vel_y*ny)))*ny;
          }
         else
          {
           nx = 0.0000000000000000;
           ny = 0.0000000000000000;
           image_image_x[i][j] = 0.0000000000000000;          /*Separation between centres*/
           image_image_forces[i][j][0] = 0.0000000000000000;/*Repulsive force, x component*/
           image_image_forces[i][j][1] = 0.0000000000000000;/*Repulsive force, y component*/
          }
                                               
         /*Use the symmetry of free_forces to reduce the number of calculations*/
         image_image_forces[j][i][0] = -(image_image_forces[i][j][0]);
         image_image_forces[j][i][1] = -(image_image_forces[i][j][1]);
         image_image_x[j][i] = image_image_x[i][j];
        }
      }
/*____________________________________________________________________________*/           
      /*Detect a collision between free particles and wall prticles*/
      for(i = 0; i < n_max; i++)
       {
        for(j = 0; j < 44; j++)
         {
          R1R2 = free_particle[i][9][0] + wall_particle[j][9][0];
          
          r1r2 = sqrt((pow((wall_particle[j][2][0] - free_particle[i][2][0]),2.0000000000000000))
                +(pow((wall_particle[j][3][0] - free_particle[i][3][0]),2.0000000000000000)));
                
          red_mass = ((free_particle[i][8][0]*wall_particle[j][8][0])/(free_particle[i][8][0] + wall_particle[j][8][0]));
          
          rel_vel_x = (free_particle[i][0][0] - wall_particle[j][0][0]);
         
          rel_vel_y = (free_particle[i][1][0] - wall_particle[j][1][0]);
                
          if(r1r2 < R1R2)
          {
           /*Increase the Coordination Number by 1.0 for each collision*/
           free_particle[i][10][0] += 1.0;
           wall_particle[j][10][0] += 1.0;
           /*Normal force x, component*/
           nx = (free_particle[i][2][0] - wall_particle[j][2][0])/r1r2;
           /*Normal force y, component*/
           ny = (free_particle[i][3][0] - wall_particle[j][3][0])/r1r2;
           
           /*Overlap distance of the two particles*/
           wall_x[i][j] = R1R2 - r1r2;
                       
           /*Repulsive Force, x component*/  
           wall_free_forces[i][j][0] = ((kn*(wall_x[i][j]))-((gamma*red_mass)*(rel_vel_x*nx)))*nx;
           /*Repulsive Force, y component*/
           wall_free_forces[i][j][1] = ((kn*(wall_x[i][j]))-((gamma*red_mass)*(rel_vel_y*ny)))*ny;
          }
         else
          {
           free_particle[i][10][0] += 0.0;
           wall_particle[j][10][0] += 0.0;
           nx = 0.0000000000000000;
           ny = 0.0000000000000000;
           wall_x[i][j] = 0.0000000000000000;          /*Separation between centres*/
           wall_free_forces[i][j][0] = 0.0000000000000000;/*Repulsive force, x component*/
           wall_free_forces[i][j][1] = 0.0000000000000000;/*Repulsive force, y component*/
          }
          
       }
      }    
/*____________________________________________________________________________*/     
     /*Detect a collision between free particles and image free particles*/
     for (i = 0; i < n_max; i++)
      {
       for (j = 0; j < n_max; j++)
        {
         R1R2 = free_particle[i][9][0] + image_free_particle[j][9][0];
         
         r1r2 = sqrt((pow((image_free_particle[j][2][0] - free_particle[i][2][0]),2.0000000000000000))
                +(pow((image_free_particle[j][3][0] - free_particle[i][3][0]),2.0000000000000000)));
                
         red_mass = ((free_particle[i][8][0]*image_free_particle[j][8][0])/(free_particle[i][8][0] + image_free_particle[j][8][0]));
         
         rel_vel_x = (free_particle[i][0][0] - image_free_particle[j][0][0]);
         
         rel_vel_y = (free_particle[i][1][0] - image_free_particle[j][1][0]);
         
                                               
         if(r1r2 < R1R2)
          {
           /*Increase the Coordination Number by 1.0 for each collision*/
           free_particle[i][10][0] += 1.0;
           image_free_particle[j][10][0] += 1.0;
           /*Normal force x, component*/
           nx = (free_particle[i][2][0] - image_free_particle[j][2][0])/r1r2;
           /*Normal force y, component*/
           ny = (free_particle[i][3][0] - image_free_particle[j][3][0])/r1r2;
           
           /*Overlap distance of the two particles*/
           image_x[i][j] = R1R2 - r1r2;
                       
           /*Repulsive Force, x component*/  
           image_free_forces[i][j][0] = ((kn*(image_x[i][j]))-((gamma*red_mass)*(rel_vel_x*nx)))*nx;
           /*Repulsive Force, y component*/
           image_free_forces[i][j][1] = ((kn*(image_x[i][j]))-((gamma*red_mass)*(rel_vel_y*ny)))*ny;
           
           
          }
         else
          {
           free_particle[i][10][0] += 0.0;
           image_free_particle[j][10][0] += 0.0;
           nx = 0.0000000000000000;
           ny = 0.0000000000000000;
           image_x[i][j] = 0.0000000000000000;          /*Separation between centres*/
           image_free_forces[i][j][0] = 0.0000000000000000;/*Repulsive force, x component*/
           image_free_forces[i][j][1] = 0.0000000000000000;/*Repulsive force, y component*/
          }
                                               
         /*Use the symmetry of image_free_forces to reduce the number of calculations*/
         image_free_forces[j][i][0] = -(image_free_forces[i][j][0]);
         image_free_forces[j][i][1] = -(image_free_forces[i][j][1]);
         image_x[j][i] = image_x[i][j];
        }
      }
      /*Detect a collision between an image_free_particle and a wall_particle*/
      for (i = 0; i < n_max; i++)
      {
       for (j = 0; j < 44; j++)
        {
         R1R2 = wall_particle[j][9][0] + image_free_particle[i][9][0];
         
         r1r2 = sqrt((pow((wall_particle[j][2][0] - image_free_particle[i][2][0]),2.0000000000000000))
                +(pow((wall_particle[j][3][0] - image_free_particle[i][3][0]),2.0000000000000000)));
                
         red_mass = ((image_free_particle[i][8][0]*wall_particle[j][8][0])/(image_free_particle[i][8][0] + wall_particle[j][8][0]));
         
         rel_vel_x = (image_free_particle[i][0][0] - wall_particle[j][0][0]);
         
         rel_vel_y = (image_free_particle[i][1][0] - wall_particle[j][1][0]);
                                               
         if(r1r2 < R1R2)
          {
           /*Normal force x, component*/
           nx = (image_free_particle[i][2][0] - wall_particle[j][2][0])/r1r2;
           /*Normal force y, component*/
           ny = (image_free_particle[i][3][0] - wall_particle[j][3][0])/r1r2;
           
           /*Overlap distance of the two particles*/
           wall_image_x[i][j] = R1R2 - r1r2;
                       
           /*Repulsive Force, x component*/  
           wall_image_forces[i][j][0] = ((kn*(wall_image_x[i][j]))-((gamma*red_mass)*(rel_vel_x*nx)))*nx;
           /*Repulsive Force, y component*/
           wall_image_forces[i][j][1] = ((kn*(wall_image_x[i][j]))-((gamma*red_mass)*(rel_vel_y*ny)))*ny;
          }
         else
          {
           nx = 0.0000000000000000;
           ny = 0.0000000000000000;
           wall_image_x[i][j] = 0.0000000000000000;          /*Separation between centres*/
           wall_image_forces[i][j][0] = 0.0000000000000000;/*Repulsive force, x component*/
           wall_image_forces[i][j][1] = 0.0000000000000000;/*Repulsive force, y component*/
          }
                                               
        }
      }
    time_stamp();
    trace(func_name,action_end);
}
