using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class PlayerMovement : MonoBehaviour
{
    public CharacterController2D controller;
    public Animator animator;

    float horisontal_move = 1f;
    public float speed = 20f;
    bool jump = false;
    bool isDead = false;

    public Transform Start;

    void Update() 
    {
    
        animator.SetFloat("Speed", horisontal_move * speed);
        if(Input.GetButtonDown("Jump"))
        {
            jump = true;
            animator.SetBool("IsJumping", true);
        }
    }

    public void OnLanding() 
    {
        animator.SetBool("IsJumping", false);
    }

    void FixedUpdate() 
    {
        controller.Move(horisontal_move * speed * Time.fixedDeltaTime, false, jump);
        speed += (float)(transform.position.x - Start.position.x) * 0.00001f;
        jump = false;
        
    }
}
