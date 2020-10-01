
      int intersectPoint(Node* head1, Node* head2)
      {
         int l1=0;
         int l2=0;
         
      struct Node*temp=head1;
         
         while(temp!=NULL)
         {
            l1++;
            temp=temp->next;
         }
         
         
         temp=head2;
         
         
         while(temp!=NULL){
            
            l2++;
            
            temp=temp->next;
         }
         
         
         if(l1>l2){
            
            int diff =l1-l2;
            
            
            while(diff>0){
               
               head1=head1->next;
               diff--;
            }
            
         }
         
         else if(l1<l2){
            
            int diff =l2-l1;
            
            
            while(diff>0){
               
               head2=head2->next;
               diff--;
            }
            
            
         }
      
         while(head1!=NULL&&head2!=NULL)
         {
            
            if(head1==head2){
               return head1->data;
            }
            
            else{
               
               if(head1!=NULL){
               head1=head1->next;     
               }
                  if(head2!=NULL)
                  {
               head2=head2->next;
         
                  }
               
               
                           
            }
            
         }
         
         return -1;      
      }
