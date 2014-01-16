;; c-c the ergodox.srt file
;; switch to empty .c file
;; m-x erg-test-create

(require 'eieio)

;;mods
;;	kprrel,	saltgrprre,	saltgrprre,	saltgrprre,	sshprre,	sshprre,	kprrel,
;; kprrel,	sshprre,	kprrel,	kprrel,	kprrel,	kprrel,	lpush1,
;; lpop1 
(setq erg-layout  '(
                    (;;0
                     ;; unused
                     0
                     ;; left hand
                     _esc	(_8 :a)	(_7 :a)	(_0 :a)	(_8 :s)	(_0 :s)	_esc	
                     _altL	(_comma :s)	_comma	_period	_P	_Y	1	
                     _ctrlL    _A	_O	_E	_U	_I	
                     _shiftL	50	_Q	_J	_K	_X	1	
                     _guiL	50	_backslash	(:l 2)	(:l 1)	
                     _ctrlL	_altL	
                     0	0	_ctrlL	
                     _bs	_tab	_shiftL
                     ;; right hand 51 was got with xev 45 wtih random trial and terror
                     2	(50 :s)	(_9 :s)	45	(_9 :a)	(_1 :s)	(_3 :s)	
                     _bracketL	_F	_G	_C	_R	_L	_altL	
                     _D	_H	_T	_N	_S	_ctrlL	
                     1	_B	_M	_W _V _Z	_shiftL	
                     (:l 1 ) 	(:l 2)	_arrowU	KEY_RightArrow	_guiR	
                     _altL	_ctrlL	
                     _ctrlL	0	0	
                     _shiftL	_enter	_space	

                     )
                    (;;1	
		     ;; unused
                     0
                     ;; left hand
                     KEY_CapsLock	KEY_7_Ampersand	(0x2F :s)	(0x30 :s)	0	0	0	
                     KEY_LeftAlt	0	0	KEY_UpArrow	KEY_PageUp	0	1	
                     KEY_LeftControl	KEY_Home	KEY_LeftArrow	KEY_DownArrow	KEY_RightArrow	KEY_End	
                     KEY_LeftShift	0	0	0	KEY_PageDown	0	0	
                     0	0	0	0	0	
                     0	0	
                     0	0	0	
                     0	0	0	
                     ;; right hand
                     0	0	KEYPAD_NumLock_Clear	KEYPAD_Slash	KEYPAD_Asterisk	KEYPAD_Minus	0	
                     KEYPAD_Period_Delete	0	_7_kp	_8_kp	_9_kp	KEYPAD_Plus	KEY_RightAlt	
                     _0_kp	                    _4_kp	_5_kp	_6_kp	0	KEY_RightControl	
                     _0_kp	0	                _1_kp	_2_kp	_3_kp	0	KEY_RightShift	
                     0	0	0	0	0	
                     0	0	
                     0	0	0	
                     0	0	0	
                     )
                    (;;2
                     ;; unused
                     (0 dbtldr)
                     ;; left hand
                     0	0	0	0	0	0	0	
                     0	0 	0	(_7 :a)	(_0 :a)	(45 :a)	0	
                     0	(KEY_Slash_Question :s)	KEY_Slash_Question	(_8 :s)	(_9 :s)	(0x64 :a) ;;84 / 85 * 
                     0	(45 :s)	 (_2 :a)	(_8 :a)	(_9 :a)	(84 :a)	0	
                     0	0	0	0	0	
                     0	0	
                     0	0	0	
                     0	0	0	
                     ;; right hand
                     2	0	_F10 _F11	_F12	KEYPAD_Minus	0	
                     0	0	_F7  _F8	_F9	KEYPAD_Plus	0	
                     0   	_F4  _F5	_F6	KEYPAD_Plus	0	
                     0	0	_F1  _F2	_F3	KEY_ReturnEnter	0	
                     0	0	KEYPAD_Period_Delete	KEY_ReturnEnter	0	
                     0	0	
                     0	0	0 0	
                     0	0		
                     )
                    ))

;;empty layer
(setq erg-empty-layer
      '(
  
	  0	

	  0	0	0	0	0	0	0	
	  0	0	0	0	0	0	0	
	  0	0	0	0	0	0	
	  0	0	0	0	0	0	0	
	  0	0	0	0	0	
	  0	0	
	  0	0	0	
	  0	0	0	

	  0	0	0	0	0	0	0	
	  0	0	0	0	0	0	0	
	  0	0	0	0	0	0	
	  0	0	0	0	0	0	0	
	  0	0	0	0	0	
	  0	0	
	  0	0	0	
	  0	0	0	
	  ))


(defun erg-pad-layers (layers)
;;layout must be padded to 9 layers
  (let ((l layers)) (while (> 9 (length l)) (setq l (append l (list erg-empty-layer)))) l)

)

(defun erg-test-create ()
  (interactive) ;;doesnt really have to be but is convenient
  (switch-to-buffer "jv-mod.c")
  (erase-buffer)
  (erg-create-layout-file "mupp" erg-layout)
  )


(defun erg-keyfunc (sym)
  (or (cadr (assoc sym '((:a saltgrprre) (:s sshprre)))) sym)
)

;;from info
;;run in an empty .c buffer
(defun erg-create-layout-file (classname layers)
  (if (not (srecode-table))
      (error "No template table found for mode %s" major-mode))
  ;;(setq fieldlist (car fieldlist))
  (let ((temp (srecode-template-get-table (srecode-table) "classdecl:ergodox-mod"))
        ;; Create a new dictionary
        (newdict (srecode-create-dictionary) )
        (childdict))

    (mapcar (lambda (layer)
              (setq childdict (srecode-dictionary-add-section-dictionary
                               newdict "LAYERS"))
              (mapcar 
               (lambda (key)
                 (let ((subdict (srecode-dictionary-add-section-dictionary
                                 childdict "KEYS")))
                   (message "key '%s'" key)
                   (cond
                    ((eq 0 key) ;;0 map to 0 NULL NULL
                     (srecode-dictionary-set-value subdict "NAME" (format "%s" 0))
                     (srecode-dictionary-set-value subdict "PRESS" "NULL")
                     (srecode-dictionary-set-value subdict "RELEASE" "NULL")                         )

                    ((atom key) ;;atom map to atom kprrel kprrel, a keypress
                     (srecode-dictionary-set-value subdict "NAME" (format "%s" key))
                     (srecode-dictionary-set-value subdict "PRESS" "kprrel")
                     (srecode-dictionary-set-value subdict "RELEASE" "kprrel")                          )

                    ((and  (= 2 (length key)) (eq :l (car key))) ;; a special case for push/pop
                     (srecode-dictionary-set-value subdict "NAME" (format "%s" (cadr key)))
                     (srecode-dictionary-set-value subdict "PRESS" (format "lpush%s" (cadr key)))
                     (srecode-dictionary-set-value subdict "RELEASE" (format "lpop%s"  (cadr key))))

                    ((= 2 (length key));; atom atom map to atom atom atom
                     (srecode-dictionary-set-value subdict "NAME" (format "%s" (car key)))
                     (srecode-dictionary-set-value subdict "PRESS" (format "%s" (erg-keyfunc  (cadr key))))
                     (srecode-dictionary-set-value subdict "RELEASE" (format "%s" (erg-keyfunc  (cadr key)))))

                    (t (srecode-dictionary-set-value subdict "NAME" (format "%s"  (car key))) ;; full form 3 atoms, map to atoms
                       (srecode-dictionary-set-value subdict "PRESS" (format "%s" (erg-keyfunc (cadr key))))
                       (srecode-dictionary-set-value subdict "RELEASE" (format "%s" (erg-keyfunc (caddr key)))))
                    )
                   


                   ))
               layer)              
              )
	    (erg-pad-layers  layers))


    ;; Some templates have arguments that need to be resolved.
    
    (srecode-resolve-arguments temp newdict)

    ;; Do the expansion
    
    (srecode-insert-fcn temp newdict)
    (indent-region (point-min) (point-max))
    (setq erg-dict-dbg newdict)
    ))

