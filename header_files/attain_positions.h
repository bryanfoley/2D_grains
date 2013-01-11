void attain_positions (double free_particle[n_max][m_max][z_max],
                       double image_free_particle[n_max][m_max][z_max],
                       double wall_particle[44][m_max][z_max])
{
     int i;
     
     for(i = 0; i < n_max; i++)
      {
         fscanf(in_fptr94,"\t%lf\t%lf",&free_particle[i][2][0],&free_particle[i][3][0]);
      }
      
     for(i = 0; i < n_max; i++)
      {
       fscanf(in_fptr95,"\t%lf\t%lf",&image_free_particle[i][2][0],&image_free_particle[i][3][0]);
      }
      
     for(i = 0; i < 44; i++)
      {
       fscanf(in_fptr96,"\t%lf\t%lf",&wall_particle[i][2][0],&wall_particle[i][3][0]);
      }
}
