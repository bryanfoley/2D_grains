void set_free_positions(double free_particle[n_max][m_max][z_max])
{
     for(i = 0; i < n_max; i++)
      {
         fscanf(in_fptr1,"%lf\t%lf\n",&free_particle[i][2][0],&free_particle[i][3][0]);
      }
}
